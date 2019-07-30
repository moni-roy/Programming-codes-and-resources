#include <stdio.h>
int ok(int n){
    int ret = 0;
    while(n>0){
        ret+=(n%10);
        n/=10;
    }
    return (ret%4);
}
void Main(){
    int n,a;
    scanf("%d",&a);
    n = a;
    while(ok(n)) {n++;}
    printf("%d\n",n);
    return;
}
int main(){
    Main();
    return 0;
}