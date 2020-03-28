#include <bits/stdc++.h>
using namespace std;
long long nCr[55][55];
void NCR() {
    for(int i=1; i<52; i++) {
        nCr[i][0]=nCr[i][i]=1;
        for(int j=1; j<i; j++)
            nCr[i][j]=nCr[i-1][j]+nCr[i-1][j-1];
    }
}

int main()
{
	NCR();
	int ts,n,a,b,w;
	cin>>ts;
	while(ts--){
		cin>>n>>a>>b>>w;
		if(a==b && a+b==n){
			cout<<"RECOUNT!"<<endl;
			continue;
		}
		if(n%2){
			if(b==n/2+1)
			{				
				cout<<"RECOUNT!"<<endl;
				continue;
			}
		}
		else{
			if(b==n/2){
				cout<<"RECOUNT!"<<endl;
				continue;
			}
		}
		int t = n-a-b;
		if(t+a<b){
			cout<<"RECOUNT!"<<endl;
			continue;
		}
		double s = 0;
		int nn = n/2+1;
		nn = max(0,nn-a);
		for(int i=nn;i<=t;i++){
			s+=nCr[t][i];
		}
		for(int i =0;i<t;i++){
			s/=2.0;
		}
		s = 100.0*s;
		if(nn==0) s = 100;
		if(s>w){
			cout<<"GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!"<<endl;
		}
		else cout<<"PATIENCE, EVERYONE!"<<endl;
	}
	return 0;
}
