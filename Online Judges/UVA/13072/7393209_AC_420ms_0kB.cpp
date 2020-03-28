#include <bits/stdc++.h>
using namespace std;

int sv[1001][1001],vs[1001][1001];
string s,rs;
int main()
{
    while(cin>>s)
    {
        int l = s.size();
        rs = s;
        reverse(rs.begin(),rs.end());
        memset(sv,0,sizeof sv);
        memset(vs,0,sizeof vs);

        for(int i=1; i<=l; i++)
        {
            for(int j=1; j<=l; j++)
            {
                if(s[i-1]==rs[j-1])
                {
                    sv[i][j]=sv[i-1][j-1]+1;
                }
                else
                {
                    sv[i][j]=max(sv[i][j-1],sv[i-1][j]);
                }
            }
        }
        int ln = sv[l][l];
//        cout<<ln<<endl;
        for(int i=1; i<=l; i++)
        {
            for(int j=1; j<=l; j++)
            {
                if(s[i-1]==rs[j-1])
                {
                    vs[i][j]=1;
                }
                else if(sv[i][j-1]==sv[i][j])
                {
                    vs[i][j]=2;
                }
                else vs[i][j]=3;
            }
        }
        int ix,iy;
        for(int i=l; i>=1; i--)
        {
            for(int j=l; j>=1; j--)
            {
                if(sv[j][i]==ln && vs[j][i]==1)
                {
                    ix = j;
                    iy = i;
                    break;
                }
            }
        }
//        cout<<ix<<" "<<iy<<endl;
        string Ans ="";
        while(ix>=1 && iy>=1){
            if(vs[ix][iy]==1){
                Ans+=s[ix-1];
                ix--;
                iy--;
            }
            else if(vs[ix][iy]==2){
                iy--;
            }
            else ix--;
        }
        reverse(Ans.begin(),Ans.end());
        cout<<Ans<<endl;
    }
    return 0;
}
