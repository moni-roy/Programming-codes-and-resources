#include <bits/stdc++.h>
using namespace std;
int ts,mx,ar[1000];
string s[1000];
int main(){
	cin>>ts;
	getchar();
	for(int i=0;i<ts;i++){
		getline(cin,s[i]);
	}
	mx=0;
	for(int i=0;i<ts;i++){
		for(int j=0;j<(int)s[i].size();j++)
		{
			s[i][j]=toupper(s[i][j]);
			if(s[i][j]>='A'&&s[i][j]<='Z')
			{
				ar[s[i][j]-'A']++;
				
			}
			mx=max(mx,ar[s[i][j]-'A']);
		}
	}
	for(int i=mx;i>0;i--){
		for(int j=0;j<27;j++)
		{
			if(ar[j]==i){
				cout<<char('A'+j)<<" "<<i<<endl;
				ar[j]=0;
			}
		}
	}
	return 0;
}
