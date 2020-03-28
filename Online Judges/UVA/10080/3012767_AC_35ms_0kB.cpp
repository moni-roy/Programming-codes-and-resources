#include <bits/stdc++.h>
using namespace std;
#define M 222
int seen[M],matchR[M],nx,ny;
double s,v;
vector<int>bpGraph[M];
struct data{
	double x,y;
}a[111],b[111];
double distan(data m,data n){
	return sqrt((m.x-n.x)*(m.x-n.x)+(m.y-n.y)*(m.y-n.y));
}
bool bpm(int u)
{
	for(int v=0;v<(int)bpGraph[u].size();v++){
		int V=bpGraph[u][v];
		if(seen[V]==0){
			seen[V]=true;
			if(matchR[V]==-1||bpm(matchR[V])){
				matchR[V]=u;
				return true;
			}
		}
	}
	return false;
}
int maxBPM(){
	memset(matchR,-1,sizeof matchR);
	int result=0;
	for(int i=0;i<nx;i++){
		memset(seen,0,sizeof seen);
		if(bpm(i)){
			result++;
		}
	}
	return result;
}
int main(){
	while(cin>>nx>>ny>>s>>v)
	{
		for(int i=0;i<M;i++){
			bpGraph[i].clear();
		}
		for(int i=0;i<nx;i++){
			cin>>a[i].x>>a[i].y;
		}
		for(int i=0;i<ny;i++){
			cin>>b[i].x>>b[i].y;
		}
		for(int i=0;i<nx;i++){
			for(int j=0;j<ny;j++){
				double ds=distan(a[i],b[j]);
				ds/=v;
				if(ds<=s){
					bpGraph[i].push_back(j);
				}
			}
		}
		cout<<nx-maxBPM()<<endl;
	}
	return 0;
}
		
	
