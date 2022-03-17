#include <stdio.h>
#include "stdlib.h"
#include "strings.h"


void add(int a, int b){
    // YOUR CODE HERE
    int c=a+b;
    int l1,l2,l3,l;
    char s1[25],s2[25],s3[25];
    sprintf(s1,"%d",a);
    sprintf(s2,"%d",b);
    sprintf(s3,"%d",c);
    l1 = strlen(s1);
    l2 = strlen(s2);
    l3 = strlen(s3);
    l = ((l3>((l1>l2)?l1:l2))?l3:((l1>l2)?l1:l2));
    printf("%*s\n",l+2,s1);
    printf("+%*s\n",l+1,s2);
    for(int i=0;i<l+2;i++)
      printf("-");
    printf("\n");
    printf("%*s",l+2,s3);
}

void subtract(int a, int b){
    // YOUR CODE HERE
    int c=a-b;
    int l1,l2,l3,l;
    char s1[25],s2[25],s3[25];
    sprintf(s1,"%d",a);
    sprintf(s2,"%d",b);
    sprintf(s3,"%d",c);
    l1 = strlen(s1);
    l2 = strlen(s2);
    l3 = strlen(s3);
    l = ((l3>((l1>l2)?l1:l2))?l3:((l1>l2)?l1:l2));
    printf("%*s\n",l+2,s1);
    printf("-%*s\n",l+1,s2);
    for(int i=0;i<l+2;i++)
      printf("-");
    printf("\n");
    printf("%*s",l+2,s3);
}

void multiply(int a, int b){
    // YOUR CODE HERE
    int c=a*b;
    int l1,l2,l3,l;
    char s1[25],s2[25],s3[25],s4[25];
    sprintf(s1,"%d",a);
    sprintf(s2,"%d",b);
    sprintf(s3,"%d",c);
    l1 = strlen(s1);
    l2 = strlen(s2);
    l3 = strlen(s3);
    int num,b_num=b;
    l = ((l3>((l1>l2)?l1:l2))?l3:((l1>l2)?l1:l2));
    printf("%*s\n",l+2,s1);
    printf("x%*s\n",l+1,s2);
    for(int i=0;i<l+2;i++)
      printf("-");
    printf("\n");
    for(int i=0;i<l2;i++){
      num = b_num%10;
      if(num != 0){
        sprintf(s4,"%d",num*a);
        printf("%*s\n",l+2-i,s4);
      }
      b_num = b_num/10;
    }
    for(int i=0;i<l+2;i++)
      printf("-");
    printf("\n");
    printf("%*s",l+2,s3);
}

int main(){
    int a, b;
    char op;
    scanf("%d %c %d", &a, &op, &b);
    switch (op) {
        case '+':
            add(a, b);
            break;
        case '-':
            subtract(a, b);
            break;
        case 'x':
            multiply(a, b);
            break;
        default:
            printf("Sample input: 12 + 34");
    }
    return 0;
}