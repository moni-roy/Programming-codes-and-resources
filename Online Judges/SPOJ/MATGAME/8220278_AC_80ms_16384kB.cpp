#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ts,n,m,a[55][55];
    cin>>ts;
    while(ts--){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cin>>a[i][j];
        }
        int Ans = 0;
        for(int i=0;i<n;i++)
        {
            int p = 0;
            for(int j=m-1;j>=0;j--)
            {
                if(a[i][j]<=p)  p = a[i][j]-1;
                else p = a[i][j];
            }
            Ans ^= p;
        }
        if(Ans) cout<<"FIRST"<<endl;
        else cout<<"SECOND"<<endl;
    }
    return 0;
}
