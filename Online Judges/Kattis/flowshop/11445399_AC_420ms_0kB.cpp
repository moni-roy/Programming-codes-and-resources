#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,a[1010][1010],s[1010];
	cin>>n>>m;
	for(int i =0 ;i<n;i++) {
		for(int j = 0;j<m;j++) cin>>a[i][j];
	}
	s[0]=0;
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			if(i){
				s[i] = max(s[i],s[i-1])+a[i][j];
			}
			else{
				s[i] = s[i]+a[i][j];
			}
		}
	}
	for(int i = 0;i<n;i++) {
		if(i) cout<<" ";
		cout<<s[i];
	}
	cout<<endl;
	return 0;
}
