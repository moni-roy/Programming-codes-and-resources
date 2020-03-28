#include <bits/stdc++.h>
using namespace std;
int dx[]= {0,0,1,1,-1,-1,-1,1};
int dy[]= {1,-1,0,1,-1,1,0,-1};

int i,lx,ly,x,y,t,vs[200][200],cnt;
string s[201],ss;
void fun(int xx,int yy)
{
    cnt++;
    vs[xx][yy]=1;
    for(int i=0; i<8; i++)
    {
        int yyy=yy+dy[i];
        int xxx=xx+dx[i];
        if(xxx>=0&&xxx<lx&&yyy>=0&&yyy<ly&&vs[xxx][yyy]==0&&s[xxx][yyy]=='W')
        {
            vs[xxx][yyy]=1;
            fun(xxx,yyy);
        }
    }
}
int main()
{
    cin>>t;
    getchar();
    getchar();
    while(t--)
    {
        i=0;
        while(getline(cin,ss)&&ss.size())
        {
            //getchar();
            if(ss[0]=='L'||ss[0]=='W')
            {
                s[i++]=ss;
            }
            else
            {
                lx=i;
                ly=s[0].size();
                stringstream cs;
              //  cout<<ss<<endl;
                cs<<ss;
                cs>>x;
                cs>>y;
                //cout<<x<<" "<<y<<endl;
                memset(vs,0,sizeof vs);
                cnt=0;
                fun(x-1,y-1);
                cout<<cnt<<endl;
            }
        }
        if(t) cout<<endl;
    }
}
