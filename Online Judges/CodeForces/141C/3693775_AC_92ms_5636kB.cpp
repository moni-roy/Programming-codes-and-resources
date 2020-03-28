#include <bits/stdc++.h>
using namespace std;

struct ST{
	string nm;
	int vl;
	int hg;
	bool operator<(const ST &p) const{
		return vl<p.vl;
	}
}st[100010];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>st[i].nm>>st[i].vl;
	}
	sort(st,st+n);
	int flg=0;
	for(int i=0;i<n;i++){
		if(st[i].vl>i){
			flg=1;
			break;
		}
		int sm=i-st[i].vl+1;
		st[i].hg=sm;
		for(int j=i-1;j>=0;j--){
			if(st[i].hg<=st[j].hg) st[j].hg++;
		}
	}
	if(flg) cout<<"-1"<<endl;
	else{
		for(int i=0;i<n;i++){
			cout<<st[i].nm<<" "<<st[i].hg<<endl;
		}
	}
}
