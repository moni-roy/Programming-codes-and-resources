#include<bits/stdc++.h>
using namespace std;

int n,a[100010],c[100010],d[100010];
map<int,int> nMap,sMap;

int main()
{    
    cin>>n;
    for(int i =0;i<n;i++){
        cin>>a[i];
        nMap[a[i]] = i;
        sMap[a[i]] = i;
        c[i] = a[i];
        d[i] = a[i];
    }
    sort(a,a+n);
    int Ans = 0,Ans1 = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]!=c[i]){
            Ans++;
            c[nMap[a[i]]] = c[i];
            nMap[c[i]] = nMap[a[i]];
        }
        if(a[i]!=d[n-i-1]){
            Ans1++;
            d[sMap[a[i]]] = d[n-i-1];
            sMap[d[n-1-i]] = sMap[a[i]];
        }
    }
    cout<<min(Ans,Ans1)<<endl;
    return 0;
}
