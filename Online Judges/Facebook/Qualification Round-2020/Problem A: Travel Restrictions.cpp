#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("travel_restrictions_validation_input (1).txt", "r", stdin);
    // freopen("outputCheck.txt", "w", stdout);

    int ts, cs = 0, n;
    string in, out, res[55];
    cin >> ts;
    while (ts--)
    {
        cin >> n;
        cin >> in;
        cin >> out;
        for (int i = 0; i < n; i++)
        {
            res[i] = "";
            for (int j = 0; j < n; j++)
            {
                res[i] += 'N';
            }
        }
        for (int i = 0; i < n; i++)
        {
            int f = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (f && in[j] == 'Y' && out[j - 1] == 'Y')
                {
                    res[i][j] = 'Y';
                }
                else
                {
                    f = 0;
                    res[i][j] = 'N';
                }
            }
            f = 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (f && in[j] == 'Y' && out[j + 1] == 'Y')
                {
                    res[i][j] = 'Y';
                }
                else
                {
                    f = 0;
                    res[i][j] = 'N';
                }
            }
            res[i][i] = 'Y';
        }
        cout << "Case #" << ++cs << ":\n";
        for (int i = 0; i < n; i++)
        {
            cout << res[i] << endl;
        }
    }
    return 0;
}