#include <stdio.h>
int min(int a, int b) { return (a < b) ? a : b; }
void MRoy() {
    int n, b[111];
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) scanf("%d", b + i);
    b[n - 1] = b[n - 2];
    
    int Ans = b[0];
    for (int i = 1; i < n; i++) {
        Ans += min(b[i], b[i - 1]);
    }
    printf("%d\n",Ans);
}
int main() {
    MRoy();
    return 0;
}