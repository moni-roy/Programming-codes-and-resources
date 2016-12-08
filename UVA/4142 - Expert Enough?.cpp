#include <bits/stdc++.h>
using namespace std;

struct st{
	string s;
	int l,h;
}a[100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ts,n,x,q,cn;
	cin>>ts;
	while(ts--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].s>>a[i].l>>a[i].h;
		}
		cin>>q;
		string ss;
		while(q--){
			cin>>x;
			cn=0;
			for(int i=0;i<n;i++){
				if(a[i].l<=x && x<=a[i].h){
					cn++;
					ss=a[i].s;
				}
				if(cn>1) break;
			}
			if(cn==1)cout<<ss<<endl;
			else{
				cout<<"UNDETERMINED"<<endl;
			}
		}
		if(ts) cout<<endl;
	}
	return 0;
}
/*
2
4
HONDA 10000 45000
PEUGEOT 12000 44000
BMW 30000 75900
CHEVROLET 7000 37000
4
60000
7500
5000
10000
4
HONDA 10000 45000
PEUGEOT 12000 44000
BMW 30000 75900
CHEVROLET 7000 37000
4
60000
7500
5000
10000
*/
