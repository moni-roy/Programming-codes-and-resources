#include <stdio.h>
int n;
void Main(){
    scanf("%d",&n);
    int a = n;
    int b = n+1;
    int c = n+2;
    if(a%4==1 || b%4==1 || c%4==1){
        if(a%4==1) puts("0 A");
        else if(b%4==1) puts("1 A");
        else puts("2 A");
    }
    else if(a%4==3 || b%4==3 || c%4==3){
        if(a%4==3) puts("0 B");
        else if(b%4==3) puts("1 B");
        else puts("2 B");
    }
    else if(a%4==2 || b%4==2 || c%4==2){
        if(a%4==2) puts("0 C");
        else if(b%4==2) puts("1 C");
        else puts("2 C");
    }else{
        if(a%4==0) puts("0 D");
        else if(b%4==0) puts("1 D");
        else puts("2 D");
    }
}
int main(){
    Main();
    return;
}