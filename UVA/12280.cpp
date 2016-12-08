#include <bits/stdc++.h>
using namespace std;
int main(){
	cin>>ts;
	while(ts--){
		i=0;
		while(cin>>s[i]){
			if(st[i]=="------------------") break;
		}
		i++;
		for(int i=0;i<7;i++)
		{
			for(int j=0;j<8;j++){
				sum1+=(int)s[i][j];
			}
		}
		for(int i=0;i<7;i++)
		{
			for(int j=10;j<18;j++){
				sum2+=(int)s[i][j];
			}
		}
		if(sum1==sum2){
			for(int i=0;i<7;i++){
			for(int j=0,k=17;j<k;k--,j++){
				if(s[i][j]!=s[i][k]){
					 flg=1;
					 str=s[i][j];
					 str1=s[i][j];
					 break;
					}
				}
			}
			if(!flg) cout<<"The figure is correct."<<endl;
			else{
				for(int i=0;i<(int)str.size();i++) p1+=(int)str[i];
				for(int i=0;i<(int)str1.size();i++) p11+=(int)str1[i];
				cout<<"........||........"<<endl;
				cout<<".../\...||.../\..."<<endl;
				cout<<"../..\..||../..\.."<<endl;
				cout<<"./....\.||./....\."<<endl;
				if(p1>p11) cout<<str<<endl;
				else cout<<str1<<endl;
				cout<<"\______/||\______/"<<endl;
				cout<<"........||........ "<<endl;
		}
		else if(sum1<sum2){
			for(int i=0;i<8;i++){
			}
			}
	}
}
