#include <bits/stdc++.h>
using namespace std;
int ts,cs=0;
string mrs1,mrs2,mt1,mt2;
//char mrs1[10],mrs2[10],mt1[10],mt2[10];
int func(string st){
	return ((((st[0]-'0')*10+(st[1]-'0'))*60)+((st[3]-'0')*10+(st[4]-'0')));
}
int main(){
	cin>>ts;
	while(ts--){
		cin>>mrs1>>mrs2;
		cin>>mt1>>mt2;
		if((func(mrs1)>func(mt2))||(func(mrs2)<func(mt1))){
			cout<<"Case "<<++cs<<": Hits Meeting"<<endl;
		}
		else {
			cout<<"Case "<<++cs<<": Mrs Meeting"<<endl;
		}
		//cout<<func(mrs1)<<" "<<func(mt2)<<" "<<func(mrs2)<<" "<<func(mt1)<<endl;
	}
	return 0;
}
/*
 3
17:47 22:40
06:18 17:04
10:44 17:05
01:11 01:27
03:36 19:02
14:33 15:24
* */
