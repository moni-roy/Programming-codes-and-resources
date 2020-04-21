#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long ts;
    cin >> ts;
    while (ts--)
    {
        long long n, a, sm = 0, p = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if (p == 0)
            {
                sm = a;
                p = a;
            }
            else if (p > 0)
            {
                if (a > 0)
                {
                    if (a > p)
                    {
                        sm -= p;
                        sm += a;
                        p = a;
                    }
                }
                else
                {
                    sm += a;
                    p = a;
                }
            }
            else
            {
                if (a < 0)
                {
                    if (a > p)
                    {
                        sm -= p;
                        sm += a;
                        p = a;
                    }
                }
                else
                {
                    sm += a;
                    p = a;
                }
            }
        }
        cout<<sm<<endl;
    }

    return 0;
}