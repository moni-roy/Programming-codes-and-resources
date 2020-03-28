#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int N = 1e6 + 5, M = 1e9 + 7;

char s[N], t[] = "happiness";
int pi[N], cnt;
vector <int> v;

void preFun(const char *pat, int m) {
    int now;
    pi[0] = now = -1;
    for(int i = 1; i < m; i++) {
        while(now != -1 && pat[now + 1] != pat[i])
            now = pi[now];
        if(pat[now + 1] == pat[i]) pi[i] = ++now;
        else pi[i] = now = -1;
    }
}

void KMP(const char *txt, const char *pat) {
    int n = strlen(txt), m = strlen(pat);
    int now = -1;
    for(int i = 0; i < n; i++) {
        while(now != -1 && pat[now + 1] != txt[i])
            now = pi[now];
        if(pat[now + 1] == txt[i]) ++now;
        else now = -1;
        if(now == m - 1) {
            v.push_back(i - now);
            cnt++;
            now = pi[now];
        }
    }
}

int main() {
    scanf("%s", s);
    preFun(t, 9);
    KMP(s, t);
    int n = strlen(s);
    if(cnt > 2) puts("NO");
    else {
        puts("YES");
        if(cnt == 0) {
            int f = 1;
            for(int i = 1; i < n; i++) {
                if(s[i] == s[i - 1]) {
                    f = 0;
                    printf("%d %d\n", i, i + 1);
                    break;
                }
            }
            if(f) {
                printf("%d %d\n", 1, n);
            }
        } else if(cnt == 1) {
            printf("%d %d\n", v[0] + 2, v[0] + 5);
        } else {
            printf("%d %d\n", v[0] + 2, v[1] + 5);
        }
    }
    return 0;
}
