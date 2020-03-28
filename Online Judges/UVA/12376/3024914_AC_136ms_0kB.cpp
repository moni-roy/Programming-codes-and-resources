#include <bits/stdc++.h>
using namespace std;
int ts,cs=0,chk[101];

int n,p,id,mx=0,u,v;

int main(){
	cin>>ts;
	while(ts--){
		cin>>n>>p;
		vector<int>cost[101];
		int value[101];
		for(int i=0;i<n;i++){
			cin>>value[i];
		}
		for(int i=0;i<p;i++){
			cin>>u>>v;
			cost[u].push_back(v);
		}
		int ans=0;
		//memset(chk,-1,sizeof chk);
		for(int i=0;(int)cost[i].size()!=0;){
			mx=0;
			id=-1;
			for(int j=0;j<(int)cost[i].size();j++)
			{
				if(value[cost[i][j]]>mx){
					id=cost[i][j];
					mx=value[cost[i][j]];
					
				}//cout<<"ID "<<id<<endl;
			}
			i=id;
			//if(id>-1){
				//chk[i]=id;
			//}
			ans+=mx;
		}
		//for(int i=0;i<n;i++){
		//	cout<<chk[i]<<endl;
		//}
		//int ans=0;
		//int i=0;
		//while(chk[i]!=-1){
		//	if(chk[i]!=-1){
		//		ans+=value[chk[i]];
		//	}
		//	i=chk[i];
		//}
		cout<<"Case "<<++cs<<": "<<ans<<" "<<id<<endl;
	}
	return 0;
}
/*
 1
6 6
0 8 9 2 7 5
5 4
5 3
1 5
0 1
0 2
2 1
24 3
* */
