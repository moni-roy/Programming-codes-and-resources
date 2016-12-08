#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(cin>>n){
		int Ans=0;
		for(int i=n+1;i<=2*n;i++){
			int t=(n*i)%(i-n);
			if(t==0) Ans++;
		}
		cout<<Ans<<endl;
		for(int i=n+1;i<=2*n;i++){
			int t=(n*i)%(i-n);
			int tt=(n*i)/(i-n);
			if(t==0){
				cout<<"1/"<<n<<" = "<<"1/"<<tt<<" + 1/"<<i<<endl;
			}
		}
	}
	return 0;
}
