#include <stdio.h>
int main(){
    double score[3]={0},s1,s2,s3;
    char* pointer1,*pointer2,str0[114],type=EOF;
    int flag=0,rotation=0,existX=0,isValid=1,error1=1,error2=1;
    enum JumpType jumpType=EOF;
    for (int n=0;n<3;n++){
        scanf("%s",str0);
        pointer1=str0;jumpType=EOF;rotation=0;flag=0;existX=0;isValid=1;error1=0;error2=0;isValid=1;
        while (*pointer1!='\0'){
            if(!isValid){score[n]=0;break;}
            if(rotation==0){
                rotation=*pointer1-'0';
                if(rotation==0){isValid=0;}
                pointer1++;
                continue;
            }
            else if(jumpType==EOF){

            }
        }
    }
    return 0;
}