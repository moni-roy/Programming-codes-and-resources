ll seq[MX],check[MX],prn[MX];
ll lisLength(int sz) {
    ll ln=1,mn=0;
    check[0]=seq[0];
    prn[0]=1;
    for(int k=1; k<sz; k++) {
        if(check[ln-1]<seq[k]) {
            check[ln++]=seq[k];
            prn[k]=ln;
        } else {
            mn=lower_bound(check,check+ln,seq[k])-check;
            check[mn]=seq[k];
            prn[k]=mn+1;
        }
    }
    return ln;
}
void printLIS(int sz) {
    int len=lisLength(sz);
    stack<int>mk;
    for(int k=sz-1; k>=0; k--) {
        if(prn[k]==len) {
            mk.push(seq[k]);
            len--;
        }
    }
    while(!mk.empty()) {
        cout<<mk.top()<<endl;
        mk.pop();
    }
}
