#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define ul unsigned long

/*检测是不是回文，这里的old是指去除过多余数字和符号的字符串，new是指*/
int IsPalin(char *old, char *new, ul start, ul end);

/*会返回字符的总长度不包含‘\0’ 且不改变原先的字符长度 */
int del_pun_digit(char *old, char *new, ul start, ul end);

/*执行指令0 */
void com0(char *old, char *new, ul start, ul end);

/* 执行指令1*/
void com1(char *old, ul index, char c);

/*执行指令2 */
void com2(char *old, char *a);

char read(char *line);


int main(void) {
	char init[20000];
	char line[20000], new[20000], temp[20000], rubbish[20000];
	ul Num_Com;
	int i, num, j;
	gets(init);
	scanf("%lu", &Num_Com);
	gets(rubbish);
	while (Num_Com > 0) {
		gets(line);
		i = 0;
		j = 0;
		num = read(line);
		if (num == '0') {
			int l, r;
			while (!isdigit(line[i])) i++;  //检查第一个数字所在位置
			while (isdigit(line[i])) i++;
			i++;
			while (isdigit(line[i])) {
				temp[j] = line[i];
				i++;
				j++;
			}
			temp[j] = '\0';
			l = atoi(temp);
			j = 0;
			while (!isdigit(line[i])) i++;
			while (isdigit(line[i])) {
				temp[j] = line[i];
				j++;
				i++;
			}
			temp[j] = '\0';
			r = atoi(temp);
			com0(init, new, l, r);
		} else if (num == '1') {
			ul k;
			char c;
			while (!isdigit(line[i])) i++;
			while (isdigit(line[i])) i++;
			i++;
			while (isdigit(line[i])) {
				temp[j] = line[i];
				i++;
				j++;
			}
			temp[j] = '\0';
			i++;
			k = atoi(temp);
			c = line[i];
			com1(init, k, c);
		} else if (num == '2') {
			i = 0;
			j = 0;
			while (!isdigit(line[i]))i++;
			while (isdigit(line[i]))i++;
			i++;
			while (line[i] != '\0') {
				temp[j] = line[i];
				i++;
				j++;
			}
			temp[j] = '\0';
			com2(init, temp);
		}
		Num_Com--;
	}
}


int IsPalin(char *old, char *new, ul start, ul end) {
	int r_po = del_pun_digit(old, new, start, end) - 1;
	int l_po = 0;
	while (l_po <= r_po) {
		if (new[l_po] != new[r_po])
			return 0;
		l_po++;
		r_po--;
	}
	return 1;
}


int del_pun_digit(char *old, char *new, ul start, ul end) {
	int j = 0;
	for (int i = start; i <= end; i++) {
		if (isalpha(old[i])) {
			new[j] = (char) tolower(old[i]);
			j++;
		}
	}
	new[j] = '\0';
	return j;
}

char read(char *line) {
	ul j = 0;
	while (!isdigit(line[j])) j++;
	return line[j];
}

void com0(char *old, char *new, ul start, ul end) {
	puts(IsPalin(old, new, start, end) ? "Yes" : "No");
}

void com1(char *old, ul index, char c) {
	old[index] = c;
}

void com2(char *old, char *a) {
	strcat(old, a);
}