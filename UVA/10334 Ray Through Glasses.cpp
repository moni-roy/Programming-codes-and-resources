#include <bits/stdc++.h>
using namespace std;

long long a[1010];

int main()
{
    a[0]=1;
    a[1]=2;
    for(int i=2;i<=1001;i++) a[i]=a[i-1]+a[i-2];
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%d\n",a[n]);
    }
    return 0;
}
