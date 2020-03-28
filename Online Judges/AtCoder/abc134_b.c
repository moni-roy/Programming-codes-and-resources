#include <stdio.h>
void MRoy() {
    int n,d;
    scanf("%d%d", &n,&d);
    printf("%d\n",(n+2*d)/(2*d+1));
}
int main() {
    MRoy();
    return 0;
}