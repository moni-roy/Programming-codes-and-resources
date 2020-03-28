#include <bits/stdc++.h>
using namespace std;

int main()
{
	int ts;
	string s;
	cin>>ts;
	while(ts--){
		cin>>s;
		int l = s.size();
		
		for(int i =l-1;i>=3;){
			int f = 0;
			if(s[i]=='?' || s[i]=='F'){
				if(s[i-1]=='?'|| s[i-1]=='E'){
					if(s[i-2]=='?'||s[i-2]=='H'){
						if(s[i-3]=='?' || s[i-3]=='C'){
							s[i-3]='C';
							s[i-2]='H';
							s[i-1]='E';
							s[i]='F';
							
							f=1;
						}
					}
				}
			}
			if(f) i-=4;
			else{
				if(s[i]=='?') s[i]='A';
				 i--;
			 }
		}
		if(s[0]=='?') s[0]='A';
		if(s[1]=='?') s[1]='A';
		if(s[2]=='?') s[2]='A';
		cout<<s<<endl;
	}
	return 0;
}

