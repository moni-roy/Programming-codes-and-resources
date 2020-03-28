
int lengthOfLongestSubstring(char * s){
    int previousIndex[227];
    for(int i = 0; i<227;i++) previousIndex[i] = -1;
    int Ans = 0, cnt = 0, pre = -1;
    for(int i = 0; s[i]; i++){
        int t = s[i];
        if(previousIndex[t]!=-1){
            pre = (pre < previousIndex[t]) ? previousIndex[t] : pre;
            cnt = (i - pre);
            previousIndex[t] = i;
            
        }
        else {
            cnt++;
            previousIndex[t] = i;
        }
        Ans = (Ans < cnt) ? cnt : Ans;
    }
    return Ans;
}

