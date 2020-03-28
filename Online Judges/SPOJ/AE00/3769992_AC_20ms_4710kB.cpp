#include <bits/stdc++.h>
using namespace std;
int n;
set<pair<int,int> >st;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j*i<=n;j++){
			st.insert(make_pair(max(i,j),min(i,j)));
		}
	}
	cout<<st.size()<<endl;
}
	
