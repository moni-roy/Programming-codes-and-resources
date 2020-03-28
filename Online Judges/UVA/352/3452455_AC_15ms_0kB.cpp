#include <bits/stdc++.h>
using namespace std;
int sv[30][30],n,cnt,cs=0;
char ch;
void fun(int x,int y)
{
    if(x>=0&&y>=0&&x<n&&y<n&&sv[x][y]==0)
    {
        sv[x][y]=1;
        fun(x+1,y);
        fun(x+1,y+1);
        fun(x+1,y-1);
        fun(x-1,y+1);
        fun(x,y+1);
        fun(x,y-1);
        fun(x-1,y);
        fun(x-1,y-1);
    }
}
int main()
{
    while(cin>>n)
    {
        memset(sv,0,sizeof sv);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>ch;
                if(ch=='0') sv[i][j]=1;
            }
        }
        cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(sv[i][j]==0)
                {
                    cnt++;
                    fun(i,j);
                }
            }
        }
        cout<<"Image number "<<++cs<<" contains "<<cnt<<" war eagles."<<endl;
        //cout<<cnt<<endl;
    }
}
