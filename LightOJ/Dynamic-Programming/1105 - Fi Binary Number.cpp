#include <bits/stdc++.h>
using namespace std;
int fib[100],ts,cs=0,n;

string fun(int n){
	int i;
	for(i=1;i<50;i++) if(fib[i]>n) break;
	i--;
	int flg=1,sm=fib[i];
	string ret="1";
	for(int k=i-1;k>0;k--){
		if(sm+fib[k]<=n&&flg){
			sm+=fib[k];
			flg=0;
			ret+='1';
		}
		else{
			flg=1;
			ret+='0';
		}
	}
	return ret;
}
void fibo(){
	fib[1]=1;
	fib[0]=1;
	for(int i=2;i<50;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
}
int main(){
	fibo();
	cin>>ts;
	while(ts--){
		cin>>n;
		cout<<"Case "<<++cs<<": "<<fun(n)<<endl;
	}
}
