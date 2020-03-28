#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        set<pair<int,int> >st;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j*i<=n;j++)
            {
                st.insert(make_pair(min(i,j),max(i,j)));
            }
        }
        cout<<st.size()<<endl;
    }
}
