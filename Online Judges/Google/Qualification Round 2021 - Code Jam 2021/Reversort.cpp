#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ts, cs = 0;
    cin >> ts;
    while (ts--)
    {
        int n, a[101], ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n - 1; i++)
        {
            int ii = i;
            for (int j = i; j < n; j++)
            {
                if (a[ii] > a[j])
                {
                    ii = j;
                }
            }
            for(int j = i, jj = ii; j<jj;j++, jj--) swap(a[j], a[jj]);
            ans += ii - i + 1;
        }
        cout << "Case #" << ++cs << ": " << ans << endl;
    }

    return 0;
}