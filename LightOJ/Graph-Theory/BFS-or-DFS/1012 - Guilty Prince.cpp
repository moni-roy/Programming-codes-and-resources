    /****************************************************************************
     * Problem name: 1012 - Guilty Prince
     * Problem link : http://www.lightoj.com/volume_showproblem.php?problem=1012
     *
     * Using Recurtion solution
     * **************************************************************************/
     
    #include <bits/stdc++.h>
    using namespace std;
     
    ///***************variable********************
    bool check_land[21][21];
    int cnt,w,h;
     
    ///*************recursive DFS******************
    void dfs(int x, int y)
    {
        if(x>0 && x<=w && y>0 && y<=h && !check_land[x][y])
        {
            cnt++;
            check_land[x][y]=true;
            dfs(x+1,y);
            dfs(x,y+1);
            dfs(x-1,y);
            dfs(x,y-1);
        }
       
    }
     
    ///******************main function*************
    int main()
    {
        int ts,cs=0;
        cin>>ts;
        while(ts--)
        {
            memset(check_land,0,sizeof check_land);
            cnt=0;
            int x,y;
            cin>>w>>h;
            for(int j=1;j<=h;j++)
            {
                for(int i=1;i<=w;i++)
                {
                    char ch;
                    cin>>ch;
                    if(ch=='#') check_land[i][j]=true;
                    if(ch=='@') x=i,y=j;
                }
            }
            dfs(x,y);
            cout<<"Case "<<++cs<<": "<<cnt<<endl;
        }
        return 0;
    }
     
