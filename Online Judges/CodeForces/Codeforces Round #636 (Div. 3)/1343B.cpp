#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ts;
    cin >> ts;
    while (ts--)
    {
        int n;
        cin >> n;
        if (n % 4 == 0)
        {
            cout << "YES" << endl;
            int sm = 0;
            for (int i = 2; i <= n; i += 2)
            {
                sm += i;
                cout << i << " ";
            }
            for (int i = 1; i < n - 1; i += 2)
            {
                sm -= i;
                cout << i << " ";
            }
            cout << sm << endl;
        }
        else
            cout << "NO" << endl;
    }
}