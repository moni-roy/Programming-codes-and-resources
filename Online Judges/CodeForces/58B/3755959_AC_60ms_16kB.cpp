#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>v,as;
int main(){
	cin>>n;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			if(n/i==i) v.push_back(i);
			else{
				v.push_back(i);
				v.push_back(n/i);
			}
		}
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;){
		as.push_back(v[i]);
		int j;
		for(j=i-1;j>=0;j--){
			if(v[i]%v[j]==0){
				i=j;
				break;
			}
		}
		if(j<0) break;
	}
	as.push_back(1);
	if(n!=1)as.push_back(n);
	sort(as.begin(),as.end());
	for(int i=as.size()-1;i>=0;i--){
		cout<<as[i]<<" ";
	}
	cout<<endl;
}
	
