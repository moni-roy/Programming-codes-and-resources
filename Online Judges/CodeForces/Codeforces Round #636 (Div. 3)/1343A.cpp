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
        int f = 1;
        for (int i = 4; i<=n+10; i=i*2)
        {
            if(n%(i-1)==0){
                cout<<n/(i-1)<<endl;
                break;
            }
        }
    }
}