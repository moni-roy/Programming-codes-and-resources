class Solution {
public:
    map<long long, bool> mp;
    bool isHappy(int n) {
        while(n!=1 && mp.find(n)==mp.end()) {
            mp[n]=1;
            long long r = 0;
            while(n){
                int t = n%10;
                n/=10;
                r += (t*t);
            }
            n = r;
        }
        return n==1;
    }
};
