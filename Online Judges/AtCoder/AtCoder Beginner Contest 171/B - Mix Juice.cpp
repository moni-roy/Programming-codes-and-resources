#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, a[100020];
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int Ans = 0;
    for (int i = 0; i < k; i++)
        Ans += a[i];
    cout << Ans << endl;
    return 0;
}