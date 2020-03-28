#include <bits/stdc++.h>
using namespace std;

#define MX 1000000
int vs[MX+1];
int PHI[MX+1];
vector<int> PRM;

void eulerPhi(){
    PHI[1]=1ll;
    for(int i=2; i <= MX ; i++){
        if(vs[i]==0){
            vs[i]=i;
            PHI[i]=i-1;
            PRM.push_back(i);
        }
        else{
            if(vs[i]==vs[i/vs[i]]){
                PHI[i]=PHI[i/vs[i]]*vs[i];
            }
            else{
                PHI[i]=PHI[i/vs[i]]*(vs[i]-1);
            }
        }
        for(int j=0; j<(int)PRM.size() && PRM[j]<=vs[i] && i*PRM[j]<=MX; j++){
            vs[i*PRM[j]]=PRM[j];
        }
    }
}
vector<int>v[MX+1];
void pre(){
	eulerPhi();
	v[0].push_back(1);
	for(int i=2;i<=MX;i++){
		int t = i;
		int k = 1;
		while(k<=20 && PHI[t]!=1){
			t = PHI[t];
			k++;
		}
		if(k<=20){
			v[k].push_back(i);
		}
	}
}

int main()
{
	pre();
	int ts,x,y,k;
	cin>>ts;
	while(ts--){
		cin>>x>>y>>k;
		int u = upper_bound(v[k].begin(),v[k].end(),y)-v[k].begin();
		int l = upper_bound(v[k].begin(),v[k].end(),x-1)-v[k].begin();
		cout<<u-l<<endl;
	}
	return 0;
}
