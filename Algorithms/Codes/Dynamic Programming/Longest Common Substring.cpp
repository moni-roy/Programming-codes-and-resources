int LCS(const string& str1, const string& str2) {
    if(str1.empty() || str2.empty()) {
        return 0;
    }
    int *curr = new int [str2.size()];
    int *prev = new int [str2.size()];
    int *swap = nullptr;
    int maxSubstr = 0;
    for(int i = 0; i<str1.size(); ++i) {
        for(int j = 0; j<str2.size(); ++j) {
            if(str1[i] != str2[j]) {
                curr[j] = 0;
            } else {
                if(i == 0 || j == 0) {
                    curr[j] = 1;
                } else {
                    curr[j] = 1 + prev[j-1];
                }
                maxSubstr=max(maxSubstr,curr[j]);
            }
        }
        swap=curr;
        curr=prev;
        prev=swap;
    }
    delete [] curr;
    delete [] prev;
    return maxSubstr;
}
