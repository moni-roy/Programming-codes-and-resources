#include <bits/stdc++.h>
using namespace std;
int ts,n,vis[5050];
struct data{
	int x,y;
	bool operator<(const data &p) const{
		if(x==p.x) return y>p.y;
		return x>p.x;
	}
}st[5050];
int main(){
	cin>>ts;
	while(ts--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>st[i].x>>st[i].y;
		}
		memset(vis,0,sizeof vis);
		int cnt=0;
		sort(st,st+n);
		for(int i=0;i<n;i++){
			if(vis[i]==0){
				cnt++;
				vis[i]=1;
				int id=i;
				for(int j=i;j<n;j++){
					if(st[id].x>=st[j].x&&st[id].y>=st[j].y&&vis[j]==0){
						vis[j]=1;
						id=j;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
