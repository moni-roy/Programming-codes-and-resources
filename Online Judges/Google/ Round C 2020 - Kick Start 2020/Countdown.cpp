#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ts, cs = 0;
    cin >> ts;
    while (ts--)
    {
        int n, k, a[200001];
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int Ans = 0;
        for (int i = 0; i < n;)
        {
            if (a[i] == k)
            {
                while (i + 1 < n && a[i + 1] == a[i] - 1)
                    i++;
                if (a[i] == 1)
                    Ans++;
            }
            i++;
        }
        cout << "Case #" << ++cs << ": " << Ans << endl;
    }
}