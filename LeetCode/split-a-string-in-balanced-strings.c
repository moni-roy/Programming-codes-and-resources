int balancedStringSplit(char * s){
    int i = 0;
    int cnt = 1, ret = 0;
    char c = s[0];
    for(i = 1;s[i];i++){
        if(c==s[i]) cnt++;
        else cnt--;
        if(cnt==0) ret++;
    }
    return ret;
}
