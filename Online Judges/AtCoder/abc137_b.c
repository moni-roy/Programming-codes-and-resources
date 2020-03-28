#include <stdio.h>
void MRoy(){
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i = a-1;i>=1;i--){
        printf("%d ",b-i);
    }
    printf("%d",b);
    for(int i = 1;i<a;i++) printf(" %d",b+i);
    printf("\n");
}
int main(){
    MRoy();
    return 0;
}