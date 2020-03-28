#include <bits/stdc++.h>
using namespace std;
string s,ss;
int ls,lss;
int main(){
	cin>>s>>ss;
	ls=s.size();
	lss=ss.size();
	map<char,int>mp;
	for(int i=0;i<lss;i++){
		mp[ss[i]]++;
	}
	for(int i=0;i<ls;i++){
		for(int j='9';j>s[i];j--){
			if(mp[j]){
				s[i]=j;
				mp[j]--;
				break;
			}
		}
	}
	cout<<s<<endl;
}
	
