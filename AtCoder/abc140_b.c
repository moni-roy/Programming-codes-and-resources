#include <stdio.h>
void MRoy() {
    int n, a[30], b[30], c[30];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) scanf("%d", b + i);
    for (int i = 0; i < n - 1; i++) scanf("%d", c + i);
    int Ans = 0;
    for (int i = 0; i < n; i++) {
        Ans += b[i];
        if (i != 0) {
            if (a[i - 1] + 1 == a[i]) {
                Ans += c[a[i - 1]-1];
            }
        }
    }
    printf("%d\n",Ans);
}
int main() {
    MRoy();
    return 0;
}