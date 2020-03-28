#include <bits/stdc++.h>
using namespace std;
int a[100];
string s,st;
int main(){
	while(cin>>a[8]>>a[7]>>a[6]>>a[5]>>a[4]>>a[3]>>a[2]>>a[1]>>a[0]){
		s="";
		for(int i=8;i>1;i--){
			if(a[i]==0){}
			
			else if(a[i]<0){
				if(a[i]==-1){
					s+='-';
					s+=' ';
				}
				else{
					s+='-';
					s+=' ';
					st="";
					int tm=abs(a[i]);
					while(tm>0){
						st+=(tm%10+'0');
						tm/=10;
					}
					for(int k=st.size()-1;k>=0;k--){
						s+=st[k];
					}
				}
					s+='x';
					s+='^';
					s+=(i+'0');
					s+=' ';
			}
			else{
				s+='+';
				s+=' ';
				if(a[i]==1){
				}
				else{
					st="";
					int tm=abs(a[i]);
					while(tm>0){
						st+=(tm%10+'0');
						tm/=10;
					}
					for(int k=st.size()-1;k>=0;k--){
						s+=st[k];
					}
				}
				s+='x';
				s+='^';
				s+=(i+'0');
				s+=' ';
			}
		}
		if(abs(a[1])!=0){
			if(a[1]<0){
				s+='-';
				s+=' ';
				if(a[1]==-1){}
				else{
					st="";
					int tm=abs(a[1]);
					while(tm>0){
						st+=(tm%10+'0');
						tm/=10;
					}
					for(int k=st.size()-1;k>=0;k--){
						s+=st[k];
					}
				}
				s+='x';
				s+=' ';
			}
			else{
				s+='+';
				s+=' ';
				if(a[1]==1){
				}
				else{
					st="";
					int tm=abs(a[1]);
					while(tm>0){
						st+=(tm%10+'0');
						tm/=10;
					}
					for(int k=st.size()-1;k>=0;k--){
						s+=st[k];
					}
				}
				s+='x';
				s+=' ';
			}
		}
		if(abs(a[0])!=0){
			if(a[0]<0){
				s+='-';
				s+=' ';
				if(a[0]==-1){
					s+='1';
					}
				else{
					st="";
					int tm=abs(a[0]);
					while(tm>0){
						st+=(tm%10+'0');
						tm/=10;
					}
					for(int k=st.size()-1;k>=0;k--){
						s+=st[k];
					}
				}
				s+=' ';
			}
			else{
				s+='+';
				s+=' ';
				if(a[0]==1){
					s+='1';
				}
				else{
					st="";
					int tm=abs(a[0]);
					while(tm>0){
						st+=(tm%10+'0');
						tm/=10;
					}
					for(int k=st.size()-1;k>=0;k--){
						s+=st[k];
					}
				}
				s+=' ';
			}
		}
		if(s.size()==0) cout<<0;
		
		else if(s[0]=='+'){
			for(int i=2;i<(int)s.size()-1;i++){
				cout<<s[i];
			}
		}
		else if(s[0]=='-') {
			cout<<'-';
			for(int i=2;i<(int)s.size()-1;i++){
				cout<<s[i];
			}
		}
		cout<<endl;
	}
}
//x^5 + 22x^4 - 333x^3 + x - 1
//x^8 + x^7 + x^6 + x^5 + x^4 + x^3 + x^2 + x
//-55x^2 + 5x
//x^5 + 22x^4 - 333x^3 + x - 1
//-55x^2 + 5x
