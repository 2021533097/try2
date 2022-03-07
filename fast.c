#include "stdio.h"

long long exgcd(long long a,long long b,long long*x,long long *y);

int main(void){
    long long *x,*y,a,b;
    long long c,d;
    x = &c;
    y=&d;
    a=20,b=3;
    long long r=exgcd(a,b,x,y);
    printf("(%lld * %lld)+(%lld * %lld)= %lld\n",c,a,d,b,r);
    return 0;
}

long long exgcd(long long a,long long b,long long*x,long long *y){
    if(b == 0){
        *x=1;
        *y=0;
        return a;
    }
    long long r = exgcd(b,a%b,x, y);
    long long temp;
    temp = *x;
    *x = *y;
    *y = (temp-(a/b)*(*y));
    return r;
}
