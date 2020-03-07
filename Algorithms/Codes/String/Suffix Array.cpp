/*
 * lcp return the longest common prefix legnth 
 * between two string.
 * */
#define F first
#define S second
const int N = (int)5*(1e4 + 7);
string s;
pair<pair<int,int>,int > Suffix[N],tmpSuffix[N];
int Rank[20][N],stp;
void SortSuffix(int n){
    for(int i=0; i<=n; i++){
        Suffix[i].F.F = (int)s[i];
        Suffix[i].F.S = 0;
        Suffix[i].S = i;
    }
    stp = 0;
    sort(Suffix,Suffix+n+1);
    for(int i = 0; i <= n; i++){
        if( !i ) Rank[i][Suffix[i].S] = i;
        else if ( Suffix[i].F != Suffix[i-1].F ){
            Rank[0][Suffix[i].S] = i;
        }
        else Rank[0][Suffix[i].S] = Rank[0][Suffix[i-1].S];
    }
    for(stp = 1; ; stp++){
        for(int i = 0; i <= n; i++) {
            int firstPart = Suffix[i].S;
            int secondPart = Suffix[i].S + (1 << (stp-1));
            tmpSuffix[i].F.F = Rank[stp-1][firstPart];
            if(secondPart <= n-1) tmpSuffix[i].F.S = Rank[stp-1][secondPart];
            else tmpSuffix[i].F.S = 0;
            tmpSuffix[i].S = -firstPart;
        }
        sort(tmpSuffix, tmpSuffix+n+1);
        for(int i = 0; i <= n; i++){
            Suffix[i] = tmpSuffix[i];
            Suffix[i].S *= -1;
            if( !i ) Rank[stp][Suffix[i].S] = i;
            else if(Suffix[i].F != Suffix[i-1].F) {
                Rank[stp][Suffix[i].S] = i;
            }
            else Rank[stp][Suffix[i].S] = Rank[stp][Suffix[i-1].S];
        }
        if( (1 << stp) >= n) break;
    }
}
int lcp(int x,int y,int n) {
    int ans = 0;
    if( x == y ) return n-x;
    for(int j = stp-1; j >= 0 && x < n; j--){
        if(Rank[j][x] == Rank[j][y]){
            x += (1 << j);
            y += (1 << j);
            ans += (1 << j);
        }
    }
    return ans;
}
int main(){
    cin>>s;
    int l = s.size();
    SortSuffix(l);
    for(int i = 0; i <= l; i++)
    {
        int a = lcp(Suffix[i].S, Suffix[i-1].S,l):0;
    }
    return 0;
}
