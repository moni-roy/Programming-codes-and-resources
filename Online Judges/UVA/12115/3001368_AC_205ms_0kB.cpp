#include <bits/stdc++.h>
using namespace std;
int main(){
	int ts,cs=0,r1,c1,r2,c2,q;
	string st;
	cin>>ts;
	while(ts--){
		cin>>st>>q;
		cout<<"Square "<<++cs<<":"<<endl;
		int ln=st.size();
		for(int Q=1;Q<=q;Q++){
			cin>>r1>>c1>>r2>>c2;
			cout<<"Query "<<Q<<":"<<endl;
			for(int i=r1;i<=r2;i++){
				for(int j=c1;j<=c2;j++){
					cout<<st[ln-max(abs(ln-i),abs(ln-j))-1];
				}
				cout<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}