#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ts, cs = 0, n, ar[101][101];
    map<int, bool> mp;
    cin >> ts;
    while (ts--)
    {
        cin >> n;
        int AnsX = 0, AnsY = 0, AnsZ = 0;
        for (int i = 0; i < n; i++)
        {
            mp.clear();
            int f = 0;
            for (int j = 0; j < n; j++)
            {
                cin >> ar[i][j];
                if (mp[ar[i][j]])
                    f = 1;
                mp[ar[i][j]] = true;
            }
            AnsY += f;
        }
        for (int i = 0, j = 0; i < n; i++, j++)
            AnsX += ar[i][j];
        for (int j = 0; j < n; j++)
        {
            mp.clear();
            int f = 0;
            for (int i = 0; i < n; i++)
            {
                if (mp[ar[i][j]])
                    f = 1;
                mp[ar[i][j]] = true;
            }
            AnsZ += f;
        }
        cout << "Case #" << ++cs << ": " << AnsX << " " << AnsY << " " << AnsZ << endl;
    }
}