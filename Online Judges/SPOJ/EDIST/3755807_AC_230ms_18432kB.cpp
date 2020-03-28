#include <bits/stdc++.h>
using namespace std;
int lf,ls,sv[2001][2001],ts;
string fs,sn;
int main(){
	cin>>ts;
	while(ts--){
		cin>>fs>>sn;
		lf=fs.size();
		ls=sn.size();
		for(int i=0;i<=lf;i++){
			sv[i][0]=i;
		}
		for(int i=0;i<=ls;i++){
			sv[0][i]=i;
		}
		sv[0][0]=0;
		for(int i=1;i<=lf;i++){
			for(int j=1;j<=ls;j++){
				if(fs[i-1]==sn[j-1]){
					sv[i][j]=sv[i-1][j-1];
				}
				
				else sv[i][j]=min(sv[i-1][j-1]+1,min(sv[i-1][j]+1,sv[i][j-1]+1));
			}
		}
		cout<<sv[lf][ls]<<endl;
	}
}
