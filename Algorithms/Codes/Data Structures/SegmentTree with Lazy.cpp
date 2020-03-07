char s[200010];
int n,q,Ans,sv[200000*4+10],tr[4*200000+10];
void ini(int p,int l,int r){
    if(l==r){
        tr[p]=(s[l]=='>')?1:0;
        return ;
    }
    int md=(l+r)/2;
    ini(2*p,l,md);
    ini(2*p+1,md+1,r);
    tr[p]=tr[p*2]+tr[p*2+1];
}
void lazzy(int p,int l,int r){
    if(sv[p]){
        tr[p]=r-l+1-tr[p];
        sv[p]=0;
        if(l!=r){
            sv[2*p]=!sv[p*2];
            sv[2*p+1]=!sv[p*2+1];
        }
    }
}
void update(int p,int l,int r,int x,int y){
    if(l>=x && r<=y){
        sv[p]=!sv[p];
    }
    lazzy(p,l,r);
    if(l>y || r<x) return;
    if(l>=x && r<=y) return;
    int md=(l+r)>>1;
    update(2*p,l,md,x,y);
    update(2*p+1,md+1,r,x,y);
    tr[p]=tr[p*2]+tr[p*2+1];
}
int query(int p,int l,int r,int x,int y){
    lazzy(p,l,r);
    if(l>y || r<x) return 0;
    if(l>=x && r<=y){
        return tr[p];
    }
    int md=(l+r)>>1;
    return query(2*p,l,md,x,y)+query(2*p+1,md+1,r,x,y);
}
