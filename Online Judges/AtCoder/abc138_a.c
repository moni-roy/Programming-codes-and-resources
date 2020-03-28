#include <stdio.h>
void MRoy(){
    int a;
    char s[100];
    scanf("%d %s",&a,s);
    if(a>=3200) puts(s);
    else puts("red");
}
int main(){
    MRoy();
    return 0;
}