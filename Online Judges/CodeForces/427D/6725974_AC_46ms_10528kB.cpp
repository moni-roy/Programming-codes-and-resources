#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

const int N = (int)1e5 + 7;

string s;
pair<pair<int,int>,int > Suffix[N],tmpSuffix[N];
int Rank[20][N];
int stp;

void SortSuffix(int n)
{
    for(int i=0; i<=n; i++)
    {
        Suffix[i].F.F = (int)s[i];
        Suffix[i].F.S = 0;
        Suffix[i].S = i;
    }
    stp = 0;
    sort(Suffix,Suffix+n+1);

    for(int i = 0; i <= n; i++)
    {
        if( !i ) Rank[i][Suffix[i].S] = i;
        else if ( Suffix[i].F != Suffix[i-1].F )
        {
            Rank[0][Suffix[i].S] = i;
        }
        else Rank[0][Suffix[i].S] = Rank[0][Suffix[i-1].S];
    }

    for(stp = 1; ; stp++)
    {
        for(int i = 0; i <= n; i++)
        {
            int firstPart = Suffix[i].S;
            int secondPart = Suffix[i].S + (1 << (stp-1));
            tmpSuffix[i].F.F = Rank[stp-1][firstPart];

            if(secondPart <= n-1) tmpSuffix[i].F.S = Rank[stp-1][secondPart];
            else tmpSuffix[i].F.S = 0;
            tmpSuffix[i].S = -firstPart;
        }
        sort(tmpSuffix, tmpSuffix+n+1);

        for(int i = 0; i <= n; i++)
        {
            Suffix[i] = tmpSuffix[i];
            Suffix[i].S *= -1;
            if( !i ) Rank[stp][Suffix[i].S] = i;
            else if(Suffix[i].F != Suffix[i-1].F)
            {
                Rank[stp][Suffix[i].S] = i;
            }
            else Rank[stp][Suffix[i].S] = Rank[stp][Suffix[i-1].S];
        }
        if( (1 << stp) >= n) break;
    }
}
int lcp(int x,int y,int n)
{
    int ans = 0;
    if( x == y ) return n-x;
    for(int j = stp-1; j >= 0 && x < n; j--)
    {
        if(Rank[j][x] == Rank[j][y])
        {
            x += (1 << j);
            y += (1 << j);
            ans += (1 << j);
        }
    }
    return ans;
}

int check(string a,string b,int n)
{
    if(n < (int)a.size()) return 1;
    n-=a.size();
    return 2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2;
    cin>>s1>>s2;
    s = s1+"#"+s2+"$";
    char c = 'z'+1;
    s+=c;
    int l = s.size();
    SortSuffix(l);
    int Ans = INT_MAX,LCP[l+2];
    LCP[0]=0;
    for(int i = 1; i <= l; i++)
    {
		LCP[i] = lcp(Suffix[i-1].S,Suffix[i].S,l);
		//~ cout<<LCP[i]<<" ";
	}
	for (int i = 1; i <= l; i++)
	{	
        int a = check(s1,s2,Suffix[i].second);
        int b = check(s1,s2,Suffix[i-1].second);
        if(a==b) continue;
        
        int aa = LCP[i-1];
        int bb = LCP[i];
        int cc = LCP[i+1];
        //~ cout<<a<<" "<<b<<" = "<<aa<<" "<<bb<<" "<<cc<<endl;
        if(aa < bb && bb > cc) Ans = min(Ans,max(aa,cc)+1);
    }
    Ans = (Ans==INT_MAX)?-1:Ans;
    cout<<Ans<<endl;
    return 0;
}
