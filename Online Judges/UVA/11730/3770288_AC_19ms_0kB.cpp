#include <bits/stdc++.h>
using namespace std;
int id,a[10010],vs[10010],sv[10010],s,t,cs=0;
vector<int>prm,dv[10010];

void sieve(){
	memset(vs,0,sizeof vs);
	prm.push_back(2);
	for(int i=3;i<=1000;i++){
		if(vs[i]==0){
			prm.push_back(i);
			for(int j=i+i;i*j<=1000;j+=i){
				vs[j]=1;
			}
		}
	}
}
void fun(){
	for(int k=1;k<1001;k++){
		int x=k;
		for(int i=0;prm[i]*prm[i]<=x;i++){
			if(x%prm[i]==0){
				dv[k].push_back(prm[i]);
				while(x%prm[i]==0){
					x/=prm[i];
				}
			}
		}
		if(x>1&&x!=k) dv[k].push_back(x);
	}
}
int F(int x,int y){
	memset(sv,0,sizeof sv);
	queue<int>q;
	q.push(x);
	sv[x]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<(int)dv[u].size();i++){
			int v=u+dv[u][i];
			if(sv[v]!=0) continue;
			if(v==y) return sv[u];
			if(v<=y){
				sv[v]=sv[u]+1;
				q.push(v);
			}
		}
	}
	return -1;
}
				
int main(){
	sieve();
	fun();
	while(cin>>s>>t){
		if(s+t==0) break;
		cout<<"Case "<<++cs<<": ";
		if(s==t){
			cout<<0<<endl;
			continue;
		}
		int an=F(s,t);
		if(an!=-1) cout<<an<<endl;
		else cout<<-1<<endl;
	}
}
