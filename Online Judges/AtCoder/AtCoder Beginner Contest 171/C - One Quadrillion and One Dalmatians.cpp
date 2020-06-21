#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, d = 26;
    string str = "";
    cin >> n;
    while (n)
    {
        int t = n % 26;
        t -= 1;
        if (t < 0)
        {
            t += 26;
            n /= d;
            n -= 1;
        }
        else
        {
            n /= d;
        }
        str = str + char(t + 'a');
    }
    reverse(str.begin(), str.end());
    cout << str << endl;
    return 0;
}