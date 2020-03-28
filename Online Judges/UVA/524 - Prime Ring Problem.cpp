#include <bits/stdc++.h>
using namespace std;

int n,br[1000],vs[1001];
int a[]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};

map<int,int>prm;
int ck[1000];

void prim()
{
    prm[2]=1;
    for(int i=3; i<50; i+=2)
    {
        if(ck[i]==0)
        {
            prm[i]=1;
            for(int j=i+i; j<50; j+=i)
            {
                ck[j]=1;
            }
        }
    }
}
void print()
{
    for(int i=0; i<n; i++)
    {
        if(i<n-1) cout<<br[i]<<" ";
        else cout<<br[i]<<endl;

    }
}
void fun(int ps,int pre)
{
    if(ps==n)
    {
        int t=1+br[n-1];
        if(prm[t]==1)
        {
            print();
        }
        return ;
    }
    for(int i=1; i<n; i++)
    {
        if(vs[i]==0)
        {
            int tm=a[pre]+a[i];
            if(prm[tm]==1)
            {
                vs[i]=1;
                br[ps]=a[i];
                fun(ps+1,i);
                vs[i]=0;
            }

        }
    }
}

int main()
{
    int cs=0;
    prim();
    //for(int i=1;i<30;i++) cout<<prm[i]<<" ";
    while(cin>>n)
    {
        if(cs) cout<<endl;
        cout<<"Case "<<++cs<<":"<<endl;
        vs[0]=1;
        br[0]=1;
        fun(1,0);
    }
    return 0;
}
/*
Case 1:
1 4 3 2 5 6
1 6 5 2 3 4

Case 2:
1 2 3 8 5 6 7 4
1 2 5 8 3 4 7 6
1 4 7 6 5 8 3 2
1 6 7 4 3 8 5 2
*/
