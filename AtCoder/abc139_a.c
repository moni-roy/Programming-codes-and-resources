#include <stdio.h>
void MRoy(){
    char s[5],t[6];
    scanf("%s %s",s,t);
    int Ans = 0;
    for(int i = 0;i<3;i++) if(s[i]==t[i]) Ans++;
    printf("%d\n",Ans);
}
int main(){
    MRoy();
    return 0;
}