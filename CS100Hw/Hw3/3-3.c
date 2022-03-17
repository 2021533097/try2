#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define LIM 20000
#define False -1
enum JumpType {T, S, Lo, F, Lz, A};

static double scoreTable[4][6] = {{0.4, 0.4, 0.5,  0.5,  0.6,  1.1},
								  {1.3, 1.3, 1.7,  1.8,  2.1,  3.3},
								  {4.2, 4.3, 4.9,  5.3,  5.9,  8.0},
								  {9.5, 9.7, 10.5, 11.0, 11.5, 12.5}};

char *jump_type[6] = {"T", "S", "Lo", "F", "Lz", "A"};
int isvalid_x(char *code);
double check_valid(char *code);
int isvalid_jump(char *code);
char *s_gets(char *st, int n);
int main(void) {
	char code[LIM];
	int n=3;
	int x;
	while(n>0) {
		int i = 0, num_add = 0, valid = 0;
		double base = 0.0;
		n--;
		s_gets(code,LIM);
		x = isvalid_x(code);
		if(strchr(code,'x')) {
			*(strchr(code, 'x')) = '\0';
		}
		while (code[i] != '\0') {
			if (!isblank(code[i]) && code[i] != '\0') {
				if (code[i] == '+') {
					num_add++;
				}
				i++;continue;
			}
			valid = False;break;
		}
		if (valid == False || num_add >=3 || x==False) {
			printf("%.2f\n", 0.0);
			continue;
		}

		//接下来的代码中不会存在空格
		if(num_add == 0){
			base = check_valid(code);
			if(base < 0){
				printf("%.2f\n",0.0);
				continue;
			}
		}
		if(num_add == 1){
			char code1[LIM],code2[LIM];
			double base1,base2;
			if(!isdigit(*(strchr(code,'+')+1))){
				printf("%.2f\n",0.0);
				continue;
			}
			char *p1 = strchr(code,'+');
			*p1 = '\0';p1++;
			strcpy(code1,code);
			strcpy(code2,p1);
			base1 = check_valid(code1);
			base2 = check_valid(code2);
			if(base1 == False || base2 == False){
				printf("%.2f\n",0.0);
				continue;
			}
			base = base1+base2;
		}
		if(num_add == 2){
			char code1[LIM],code2[LIM],code3[LIM];
			double base1,base2,base3;
			if(!isdigit(*(strchr(code,'+')+1)) || !isdigit(*(strrchr(code,'+')+1))){
				printf("%.2f\n",0.0);
				continue;
			}
			char *p1 = strchr(code,'+'),*p2 =strrchr(code,'+');
			*p1 = '\0';p1++;
			*p2 = '\0';p2++;
			strcpy(code1,code);
			strcpy(code2,p1);
			strcpy(code3,p2);
			base1 = check_valid(code1);
			base2 = check_valid(code2);
			base3 = check_valid(code3);
			if(base1 == False || base2 == False || base3 == False) {
				printf("%.2f\n",0.0);
				continue;
			}
			base = base1+base2+base3;
		}
		if(x==1){base *= 1.1;}
		printf("%.2f\n",base);
	}
}

/*计算基准值*/
double Score(int rotations, enum JumpType type) {
	if (rotations < 1 || rotations > 4) {
		return False;
	}
	return scoreTable[rotations - 1][type];
}

int isvalid_jump(char *code) {
	enum JumpType jump;
	char new[LIM];
	strcpy(new, code);
	int num = 0, rec = 0;
	for (jump = T; jump <= A; jump++) {
		if (strstr(new, jump_type[jump])) {
			char *pc = strstr(new, jump_type[jump]);
			*pc = ' ';  //去除已经判断过的跳跃
			if (jump == Lz || jump == Lo) {
				*(pc + 1) = ' ';
			}
			num++; //统计跳跃的个数
			rec = jump;
			pc = strstr(new, jump_type[jump]);
			if (pc) { return False; } //有两个及以上的相同跳跃
			if (num >= 2) { return False; }
		}
	}
	//处理没有跳跃或非法输入跳跃的情况的情况
	if (num == 0) { return False; }
	return rec;
}

char *s_gets(char *st, int n) {
	char *ret_val;
	char *find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find) {
			*find = '\0';
		}
		else {
			while (getchar() != '\n'); //读取一整行
		}
	}
	return ret_val;
}

double check_valid(char *code){
	int type,rotation,nume=0,num1=0,num2=0,numq=0,num3=0;
	char *p;
    if(strlen(code)<=1) {
        return False;
    }
	if(!isdigit(code[0])){
		return False;
	}
	//因为第一位一定是数字，现在判断这个数字的大小，如果数字超过4，那么就就非法。
	rotation = atoi(code);
	if(rotation >4 || rotation <1){
		return False;
	}
	//第一位一定是数字,现在看第二位
	if(code[1] != 'T' && code[1] != 'S' && code[1] != 'L' && code[1] != 'A' && code[1] != 'F'){
		return False;
	}
	//接下来的代码第一位一定是数字

	//检查是否含有跳跃，以及跳跃是否合法，如果跳跃的数量超过两个或者没有跳跃，那么就返回False
	type = isvalid_jump(code);
	if(type == False){
		return False;
	}
    if(type == T || type == A || type == S){
        if(strlen(code) > 6){
            return False;
        }
    }
    if(type == Lo) {
        if(strlen(code) > 7) {
            return False;
        }
    }
    if(type == F) {
        if(strlen(code) > 8) {
            return False;
        }
    }
    if(type == Lz) {
        if(strlen(code) > 9) {
            return False;
        }
    }
	//防止出现诸如LLz之类的情况
	if(!isdigit(*(strstr(code,jump_type[type])-1))) {
		return False;
	}
	//接下来的代码一定有跳跃，跳跃一定在第二位
	p = (type == Lz || type == Lo)?strstr(code,jump_type[type])+2:strstr(code,jump_type[type])+1;
	//接下来p一定指向跳跃的后一位，也就是后缀记号的开始处

	//现在开始确认是否有非法字符
	while(*p!='\0'){
		if(*p!='q'&&*p!='e' && *p!='!' && *p!='<') {
			return False;
		}
		if(*p == '!') {num3++;}
		if(*p == 'e') {nume++;}
		if(*p == 'q') {numq++;}
		if(*p == '<') {
			if(*(p-1) == '<'){
				num2++;num1--;
			}
			else{
				num1++;
			}
		}
		p++;
	}
	if(type == T || type == S || type == A || type == Lo) {
		//如果在T,S,A,Lo的请况下 出现了!,e，那么非法，或者<,<<,q出现了两次及以上也非法
		if(nume>0 || num3>0 || num1>=2 || num2 >=2 || numq >=2) {
			return False;
		}
	}
	else {
		//如果在F,Lz的请况下 !,e,<,<<,q出现了两次及以上非法
		if(nume>2 || num3>2 || num1>=2 || num2 >=2 || numq >=2) {
			return False;
		}
		//现在判断其顺序
		else{
			char *p1 = strchr(code,'e');
			char *p2 = strchr(code,'!');
			char *p3 = strchr(code,'<');
			char *p4 = strchr(code,'q');
			if(p1 && p2) {
				if ((p1 > p3 || p2 > p3) && p3) {
					return False;
				}
				if ((p1 > p4 || p2 > p3) && p4) {
					return False;
				}
			}
			else if(p1){
				if(p1>p3 && p3){
					return False;
				}
				if(p1>p4 && p4){
					return False;
				}
			}
			else if(p2){
				if(p2>p3 && p3){
					return False;
				}
				if(p2>p4 && p4){
					return False;
				}
			}
			//现在上述字符一定没有问题了
		}
	}
	//此时的code一定没有非法字符,然后开始计算基准值
	if(type == Lo || type == T || type == A || type == S ){
		if(num1+num2+numq >1){
			return False;
		}
	}
	if(type == F || type == Lz){
		if(num3 + nume >1 || num1 + num2 + numq >1 ||num1 + num2 + numq+num3 + nume > 2 ){
			return False;
		}
	}
	double base = 0.0;
	rotation = rotation-num2;
	if(rotation<1){
		return base;
	}
	else{
		base = Score(rotation,type);
		for(int i=0;i<nume+num1;i++){
			base *=0.7;
		}
		return base;
	}
}

int isvalid_x(char *code) {
	char *lp=strchr(code, 'x');
	if (lp != (strchr(code, '\0') - 1)) {
		if (!lp) {
			return 0;
		}
		else {
			return False;
		}
	}
	return 1;
}