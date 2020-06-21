#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a[200010];
    int xr = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        xr ^= a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << " ";
        cout << (a[i] ^ xr);
    }
    cout << endl;
    return 0;
}