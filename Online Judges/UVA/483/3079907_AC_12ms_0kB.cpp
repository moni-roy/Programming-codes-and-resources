#include <bits/stdc++.h>
using namespace std;
string s,s2;
int ln;
string reverse(string ss){
	for(int i=0,j=(int)ss.size()-1;i<=j;i++,j--){
		swap(ss[i],ss[j]);
	}
	return ss;
}
int main(){
	while(getline(cin,s)){
		ln=s.size();
		//stringstream ss;
		s+=' ';
		s2="";
		for(int i=0;i<ln+1;i++){
			if(s[i]==' ')
			{
				s2=reverse(s2);
				cout<<s2;
				s2="";
				if(i!=ln) cout<<" ";
			}
			else{
				s2+=s[i];
				//cout<<s2<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}
		
