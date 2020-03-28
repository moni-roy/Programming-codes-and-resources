#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
set<ll>st;

int main(){
	int ts;
	cin>>ts;
	while(ts--){
		cin>>n;
		ll f=n,s=1;
		int fl=1,flg=1;
		while(s<=n && s<=f){
			if(fl && flg) cout<<f<<" / "<<s<<" = "<<n<<endl;
			s++;
			f+=n;
			//~ cout<<s<<" "<<f<<endl;
			set<int>st;
			ll ff=f,cnt=0;
			while(ff>0){
				st.insert(ff%10);
				ff/=10;
				cnt++;
			}
			if(cnt!=(int)st.size()) fl=0;
			else fl=1;
			if(cnt>10) break;
			set<int>sts;
			ll fff=s,cn=0;
			while(fff>0){
				sts.insert(fff%10);
				fff/=10;
				cn++;
			}
			if(cn!=(int)sts.size()) flg=0;
			else flg=1;			
		}
		if(ts) cout<<endl;
	}
	return 0;
}
