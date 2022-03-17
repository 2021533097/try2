#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LIM 20000

char *s_gets(char *st, int n);

char *match_else(char *a);

char *match_if(char *a);

char *match_while(char *a);

char *match_for(char *a);

char *match_else_if(char *a);

char *match_seco(char *a);

long turn(char *line);

char *match_r_curly_brace(char *a);

void put_seco(char *line, long *brace);

void put_for(char *line, long *brace);

void put_while(char *line, long *brace);

void put_if(char *line, long *brace);

void put_else(char *line, long *brace);

void put_else_if(char *line, long *brace);

char *print_indention_word(char *word, const long *brace);

int main(void) {
	int i = 0, j = 0;
	long brace = 0;
	long n;
	char line[LIM], temp[LIM];
	gets(line);
	while (!isdigit(line[i])) i++;
	while (isdigit(line[i])) {
		temp[j] = line[i];
		i++;
		j++;
	}
	temp[j] = '\0';
	n = turn(temp);
	if (n <= 0) return 0;
	line[0] = (char) 255;
	while (n > 0) {
		s_gets(line, LIM);
		if (match_r_curly_brace(line)) {
			brace--;
			print_indention_word("}", &brace);
			n--;
			continue;
		}
		if (match_seco(line)) {
			put_seco(line, &brace);
			n--;
			continue;
		}
		if (match_for(line)) {
			put_for(line, &brace);
			n--;
			continue;
		}
		if (match_while(line)) {
			put_while(line, &brace);
			n--;
			continue;
		}
		if (match_if(line)) {
			put_if(line, &brace);
			n--;
			continue;
		}
		if (match_else(line)) {
			put_else(line, &brace);
			n--;
			continue;
		}
		if (match_else_if(line)) {
			put_else_if(line, &brace);
			n--;
			continue;
		}
	}
}


char *s_gets(char *st, int n) {
	char *ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else {
			while (getchar() != ('\n' | EOF))
				continue;
		}
	}
	return ret_val;
}

long turn(char *line) {
	long i = 0, j = 0;
	while (isblank(line[i]) && line[i] != '\0') i++;
	if (line[i] == '\0') {
		return 0;
	} else {
		while (isdigit(line[i])) {
			j = 10 * j + (line[i] - 48);
			i++;
		}
		return j;
	}
}

char *match_else(char *a) {
	if (strstr(a, "else")) {
		if (strstr(a, "if")) {
			return 0;
		}
		return strstr(a, "else");
	}
	return strstr(a, "else");
}

char *match_if(char *a) {
	if (strstr(a, "if")) {
		if (strstr(a, "else")) {
			return 0;
		}
		return strstr(a, "if");
	}
	return strstr(a, "if");
}

char *match_else_if(char *a) {
	if (strstr(a, "else")) {
		if (strstr(a, "if")) {
			return strstr(a, "if");  //返回f的指针
		}
		return (strstr(a, "if"));
	}
	return (strstr(a, "else"));
}

char *match_seco(char *a) {
	if (strchr(a, ';')) {
		if (strstr(a, "else") || strstr(a, "if") || match_for(a) || match_while(a)) {
			return 0;
		} else {
			return strchr(a, ';');
		}
	}
	return strchr(a, ';');
}

char *match_for(char *a) {
	return strstr(a, "for");
}

char *match_while(char *a) {
	return strstr(a, "while");
}

char *match_r_curly_brace(char *a) {
	return (strchr(a, '}'));
}

void put_seco(char *line, long *brace) {
	char temp[LIM];
	char *lp, *rp;
	int j;
	lp = line;
	while (strchr(line, ';')) {
		j = 0;
		rp = strchr(line, ';');
		while (isblank(*lp)) lp++;
		while (lp <= rp) {
			temp[j] = *lp;
			*lp = ' ';
			lp++;
			j++;
		}
		temp[j] = '\0';
		*rp = ' ';
		print_indention_word(temp, brace);
	}
}

void put_for(char *line, long *brace) {
	char *lp, *rp, *rp1, new1[LIM], new2[LIM] = {[0]='f', [1]='o', [2]='r'};
	long i = 0;
	lp = strchr(line, '(');
	rp = strchr(line, '{') - 1;
	rp1 = rp + 1;
	*rp1 = ' ';
	while (isblank(*rp)) {
		rp--;
	}
	while (lp <= rp) {
		new1[i] = *lp;
		*lp = ' ';
		lp++;
		i++;
	}
	new1[i] = '\0';
	strcat(new1, " {");
	strcat(new2, new1);
	print_indention_word(new2, brace);
	(*brace)++;
	put_seco(line, brace);
}

void put_while(char *line, long *brace) {
	char *lp, *rp, *rp1, new1[LIM], new2[LIM] = {[0]='w', [1]='h', [2]='i', [3]='l', [4]='e'};
	long i = 0;
	lp = strchr(line, '(');
	rp = strchr(line, '{') - 1;
	rp1 = rp + 1;
	*rp1 = ' ';
	while (isblank(*rp)) {
		rp--;
	}
	while (lp <= rp) {
		new1[i] = *lp;
		*lp = ' ';
		lp++;
		i++;
	}
	new1[i] = '\0';
	strcat(new1, " {");
	strcat(new2, new1);
	print_indention_word(new2, brace);
	(*brace)++;
	put_seco(line, brace);
}

void put_if(char *line, long *brace) {
	char *lp, *rp, *rp1, new1[LIM], new2[LIM] = {[0]='i', [1]='f'};
	long i = 0;
	lp = strchr(line, '(');
	rp = strchr(line, '{') - 1;
	rp1 = rp + 1;
	*rp1 = ' ';
	while (isblank(*rp)) {
		rp--;
	}
	while (lp <= rp) {
		new1[i] = *lp;
		*lp = ' ';
		lp++;
		i++;
	}
	new1[i] = '\0';
	strcat(new1, " {");
	strcat(new2, new1);
	print_indention_word(new2, brace);
	(*brace)++;
	put_seco(line, brace);
}

void put_else(char *line, long *brace) {
	char *lp, *rp, *rp1, new1[LIM], new2[LIM] = {[0]='e', [1]='l', [2]='s', [3]='e'};
	long i = 0;
	lp = strchr(line, 'e');
	lp += 4;
	rp = strchr(line, '{') - 1;
	rp1 = rp + 1;
	*rp1 = ' ';
	while (isblank(*rp)) {
		rp--;
	}
	while (lp <= rp) {
		new1[i] = *lp;
		*lp = ' ';
		lp++;
		i++;
	}
	new1[i] = '\0';
	strcat(new1, " {");
	strcat(new2, new1);
	print_indention_word(new2, brace);
	(*brace)++;
	put_seco(line, brace);
}

void put_else_if(char *line, long *brace) {
	char *lp, *rp, *rp1, new1[LIM], new2[LIM] = {[0]='e', [1]='l', [2]='s', [3]='e', [4]=' ', [5]='i', [6]='f'};
	long i = 0;
	lp = strchr(line, '(');
	rp = strchr(line, '{') - 1;
	rp1 = rp + 1;
	*rp1 = ' ';
	while (isblank(*rp)) {
		rp--;
	}
	while (lp <= rp) {
		new1[i] = *lp;
		*lp = ' ';
		lp++;
		i++;
	}
	new1[i] = '\0';
	strcat(new1, " {");
	strcat(new2, new1);
	print_indention_word(new2, brace);
	(*brace)++;
	put_seco(line, brace);
}

char *print_indention_word(char *word, const long *brace) {
	int i = 0;
	while (i < *brace) {
		printf("    ");
		i++;
	}
	puts(word);
	return word;
}