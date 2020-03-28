#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
	cin>>s;
	int ln=s.size();
	int k=0,m=0;
	for(int i='z';i>='a';i--){
		for(int j=k;j<ln;j++){
			if(s[j]==i){
				cout<<s[j];
				m=j;
			}
		}
		k=m;
	}
	cout<<endl;
}
