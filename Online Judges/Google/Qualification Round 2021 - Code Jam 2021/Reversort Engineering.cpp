#include <bits/stdc++.h>
using namespace std;
int def(int *b, int n)
{
    int a[101];
    for (int i = 0; i < n; i++)
        a[i] = b[i];
    int ans = 0;
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
        for (int j = i, jj = ii; j < jj; j++, jj--)
            swap(a[j], a[jj]);
        ans += ii - i + 1;
    }
    return ans;
}
int main()
{
    int ts, cs = 0;
    cin >> ts;
    while (ts--)
    {
        int n, c, a[101];
        cin >> n >> c;
        for (int i = 1; i <= n; i++)
            a[i - 1] = i;
        int f = 0;
        do
        {
            int cs = def(a, n);
            if (cs == c)
            {
                f = 1;
                break;
            }
        } while (next_permutation(a, a + n));

        cout << "Case #" << ++cs << ":";
        if (f)
        {
            for (int i = 0; i < n; i++)
                cout << " " << a[i];
            cout << endl;
        }
        else
            cout << " IMPOSSIBLE" << endl;
    }

    return 0;
}