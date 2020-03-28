#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll LEFT[10011],RIGHT[10011],info[10011],id,idx,indx=0;
ll PRE[100010];
void POSTODER(ll i)
{
    if(LEFT[i])
    {
        POSTODER(LEFT[i]);
        PRE[indx]=info[LEFT[i]];
        indx++;

    }
    if(RIGHT[i])
    {
        POSTODER(RIGHT[i]);
        PRE[indx]=info[RIGHT[i]];
        indx++;

    }
}
int main()
{
    memset(LEFT,0,sizeof LEFT);
    memset(RIGHT,0,sizeof RIGHT);
    ll start;
    id=1;
    idx=0;
    cin>>start;
    info[id]=start;
    id++;
    ll val;
    idx=1;
    while(cin>>val)
    {
        info[id]=val;
        id++;
        if(val<start)
        {
            idx=1;
            if(LEFT[idx]==0)
            {
                LEFT[idx]=id-1;
            }
            else
            {
                int st=info[LEFT[idx]];

                idx=LEFT[idx];
                while(true)
                {
                    if(st>val)
                    {
                        if(LEFT[idx]==0)
                        {
                            LEFT[idx]=id-1;
                            break;
                        }
                        else
                        {
                            st=info[LEFT[idx]];
                            idx=LEFT[idx];
                        }
                    }
                    else
                    {
                        if(RIGHT[idx]==0)
                        {
                            RIGHT[idx]=id-1;
                            break;
                        }
                        else
                        {
                            st=info[RIGHT[idx]];
                            idx=RIGHT[idx];
                        }
                    }
                }
            }
        }

        else
        {

            idx=1;
            if(RIGHT[idx]==0)
            {
                RIGHT[idx]=id-1;
            }
            else
            {
                int st=info[RIGHT[idx]];
                idx=RIGHT[idx];
                while(true)
                {
                    if(st>val)
                    {
                        if(LEFT[idx]==0)
                        {
                            LEFT[idx]=id-1;
                            break;
                        }
                        else
                        {
                            st=info[LEFT[idx]];
                            idx=LEFT[idx];
                        }
                    }
                    else
                    {
                        if(RIGHT[idx]==0)
                        {
                            RIGHT[idx]=id-1;
                            break;
                        }
                        else
                        {
                            st=info[RIGHT[idx]];
                            idx=RIGHT[idx];
                        }
                    }
                }
            }
        }
    }
    POSTODER(1);
    PRE[indx]=info[1];
    indx++;
    for(ll i=0; i<indx; i++) cout<<PRE[i]<<endl;
    return 0;
}
