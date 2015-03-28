

    #include <algorithm>
    #include <bitset>
    #include <cctype>
    #include <cmath>
    #include <complex>
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    #include <ctime>
    #include <deque>
    #include <fstream>
    #include <iostream>
    #include <list>
    #include <map>
    #include <memory>
    #include <queue>
    #include <set>
    #include <sstream>
    #include <stack>
    #include <string>
    #include <utility>
    #include <vector>
    #include <iomanip>
    using namespace std;
    int tst,cas=0,num,qr,l,r,ar[100004],tree[400010],mv,lg,rg,a,j,k;
    void insert(int idx,int st, int en,int pos,int val)
    {
        if(st==en)
        {
            tree[idx]=val;
            return;
        }
        int mid=(st+en)/2;
        int left=2*idx;
        int rigt=left+1;
        if(pos<=mid) insert(left,st,mid,pos,val);
        else insert(rigt,mid+1,en,pos,val);
        tree[idx]=min(tree[left],tree[rigt]);
    }
    int query(int idx,int st, int en,int x,int y)
    {
        if(st==x&&en==y)
        {
            return tree[idx];
        }
        int mid=(st+en)/2;
        int left=2*idx;
        int rigt=left+1;
        if(y<=mid) return query(left,st,mid,x,y);
        else if(x>mid) return query(rigt,mid+1,en,x,y);
        else
        {
            return min(query(left,st,mid,x,mid),query(rigt,mid+1,en,mid+1,y));
        }
    }
    int main()
    {
        scanf("%d",&tst);                              
        while(tst--)                                    
        {
            scanf("%d%d",&num,&qr);
           
            for(int i=1;i<=num;i++)
            {
                scanf("%d",&ar[i]);
                insert(1,1,num,i,ar[i]);  
            }  
            //cout<<"Case "<<++cas<<":"<<endl;
            printf("Case %d:\n",++cas);
           
            for(int i=0;i<qr;i++)
            {
                scanf("%d%d",&l,&r);
                int ans=query(1,1,num,l,r);
                //cout<<ans<<endl;
                printf("%d\n",ans);
            }
        }
        return 0;
    }
