#include <bits/stdc++.h>
using namespace std;
#define pi 2*acos(0.0)
int main()
{
    int n;
    double ar[1000][3], r;
    while(cin >> n >> r)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> ar[i][0] >> ar[i][1];
        }
        double sum = 0;
        for(int i = 0; i < n - 1; i++)
        {
            sum += (sqrt(double(((ar[i][0] - ar[i + 1][0]) * (ar[i][0] - ar[i + 1][0])) + ((ar[i][1] - ar[i + 1][1]) * (ar[i][1] - ar[i + 1][1])))));
        }
        sum += (sqrt(double(((ar[0][0] - ar[n - 1][0]) * (ar[0][0] - ar[n - 1][0])) + ((ar[0][1] - ar[n - 1][1]) * (ar[0][1] - ar[n - 1][1])))));
        sum += (2 * r * pi );
        printf("%.2lf\n", sum);
    }
    return 0;
}
