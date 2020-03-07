struct st {
    int ls,rs,cnt=0;
};
st tr[40*MX];
int id = 0;
map<int,int> root;
void upd(int &p,int s,int e,int x,int y) {
    if(p==0) {
        p = ++id;
        tr[p].cnt = 0;
        tr[p].ls = tr[p].rs = 0;
    }
    if(s==e) {
        tr[p].cnt += y;
        tr[p].ls = tr[p].rs = 0;
        return  ;
    }
    int m = (s+e)/2;
    if(x<=m) upd(tr[p].ls,s,m,x,y);
    else upd(tr[p].rs,m+1,e,x,y);
    tr[p].cnt = tr[tr[p].ls].cnt + tr[tr[p].rs].cnt;
}

int qry(int p,int s,int e,int x,int y) {
    if(p == 0) return 0;
    if(s>=x && e<=y) return tr[p].cnt;
    int m = (s+e)/2;
    if(m>=y) return qry(tr[p].ls,s,m,x,y);
    else if(x>m) return qry(tr[p].rs,m+1,e,x,y);
    else return qry(tr[p].ls,s,m,x,m) + qry(tr[p].rs,m+1,e,m+1,y);
}
int main() {
	upd(root[v],1,MD,t,1);
	qry(root[v],1,MD,1,t);
}
