#include <bits/stdc++.h>
using namespace std;

int main(){
	int a;
	cin>>a;
	string n,s;
	vector<pair<int,string> > Ans;
	for(int i=0;i<a;i++){
		cin>>s>>n;
		if(s[0]>='0' && s[0]<='9'){
			int t = atoi(s.c_str());
			t=t/2;
			Ans.push_back({t,n});
		}else{
			int t = atoi(n.c_str());
			Ans.push_back({t,s});
		}
		sort(Ans.begin(),Ans.end());
	}
	for(auto x:Ans) cout<<x.second<<endl;
	return 0;
}
