/*
 * Find Kth sorted number in segment l to r.
 */ 
struct node
{
    int ls,rs,cnt;
};
node tr[20*MX];
int id,root[MX];
void update(int &nw,int pr,int s,int e,int pos)
{
    nw = ++id;
    tr[nw]=tr[pr];
    if(s==e && s==pos)
    {
        tr[nw].cnt ++;
        tr[nw].ls=tr[nw].rs=0;
        return;
    }
    int m = (s+e)/2;
    if(pos<=m)
    {
        update(tr[nw].ls,tr[pr].ls,s,m,pos);
    }
    else
    {
        update(tr[nw].rs,tr[pr].rs,m+1,e,pos);
    }
    tr[nw].cnt=tr[tr[nw].ls].cnt + tr[tr[nw].rs].cnt;
}
int query(int r1,int r2,int s,int e,int k)
{
    if(s==e) return s;
    int t = tr[tr[r1].ls].cnt-tr[tr[r2].ls].cnt;
    int md = (s+e)/2;
    if(t>=k) return query(tr[r1].ls,tr[r2].ls,s,md,k);
    else return query(tr[r1].rs,tr[r2].rs,md+1,e,k-t);
}
