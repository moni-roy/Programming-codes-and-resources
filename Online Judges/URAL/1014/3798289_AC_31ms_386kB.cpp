#include <bits/stdc++.h>
using namespace std;
long long int n;
vector<long long int>v;
int main(){
	while(cin>>n){
		v.clear();
		if(n==0){
			cout<<10<<endl;
			continue;
		}
		if(n<10){
			cout<<n<<endl;
			continue;
		}
		for(int i=9;i>=2;i--){
			while(n%i==0){
				v.push_back(i);
				n/=i;
			}
		}
		if(n!=1){
			cout<<-1<<endl;
			continue;
		}
		
		sort(v.begin(),v.end());
		for(int i=0;i<(int)v.size();i++){
			cout<<v[i];
		}
		cout<<endl;
		
	}
}
