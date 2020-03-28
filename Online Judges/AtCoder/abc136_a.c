#include <stdio.h>
int min(int x,int y){return (x<y)?x:y;}
int a,b,c;
int main(){
    scanf("%d%d%d",&a,&b,&c);
    b = a-b;
    printf("%d\n", c-min(b,c));
    return 0;
}