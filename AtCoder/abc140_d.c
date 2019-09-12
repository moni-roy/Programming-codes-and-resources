#include <stdio.h>
void MRoy() {
    int n, Ans = 0, k;
    char s[100002];
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) Ans++;
    }
    Ans = n - 1 < (Ans + 2 * k) ? n - 1 : Ans + 2 * k;
    printf("%d\n",Ans);
}
int main() {
    MRoy();
    return 0;
}