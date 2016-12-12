int pre[2000101];
void prefixFunction(string s) {
    int j=0,ln=s.size();
    for(int i=1; i<ln; i++) {
        while(j && s[i]!=s[j]) j=pre[j-1];
        if(s[i]==s[j]) j++;
        pre[i]=j;
    }
}
void Failure(string s) {
    int j=0,ln=s.size(),i=1;
    pre[0]=-1;
    while(i<ln) {
        if(j>-1 && s[i]!=s[j]) j=pre[j];
        else {
            j++,i++;
            pre[i]=j;
        }
    }
}
int KMP(string s,string p) {
    int ret=0,j=0,ln=s.size();;
    prefixFunction(p);
    for(int i=0; i<ln; i++) {
        while(j && s[i]!=p[j]) j=pre[j-1];
        if(s[i]==p[j]) j++;
        if(j==(int)p.size()) ret++;
    }
    return ret;
}
