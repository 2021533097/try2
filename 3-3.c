#include <stdio.h>

int main(){
    int a;
    char b;
    scanf("%d",&a);
    printf("%d\n",a);
    while(1){
    b = getchar();
    printf("b: ");
    putchar(b);
    putchar('\n');
    }
}