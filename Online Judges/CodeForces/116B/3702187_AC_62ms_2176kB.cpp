#include <bits/stdc++.h>
using namespace std;
struct st{
	int x,y,vl;
	st(){}
	st(int _x,int _y,int _v){
		x=_x;
		y=_y;
		vl=_v;
	}
	bool operator<(const st &p) const{
		return vl<p.vl;
	}
}sv[10001];
int n,m;
string s[1000];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	int k=0,cp=0,cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='P') cp++;
			if(s[i][j]=='W'){
				cnt=0;
				if(i>0) if(s[i-1][j]=='P') cnt++;
				if(i<n-1) if(s[i+1][j]=='P') cnt++;
				if(j<m-1) if(s[i][j+1]=='P') cnt++;
				if(j>=1) if(s[i][j-1]=='P') cnt++;
				sv[k]=st(i,j,cnt);
				k++;
			}
		}
	}
	sort(sv,sv+k);
	for(int i=0;i<k;i++){
		if(sv[i].vl>0){
			int xx=sv[i].x;
			int yy=sv[i].y;
			if(xx>0) if(s[xx-1][yy]=='P') {s[xx-1][yy]='W';continue;}
			if(xx<n-1) if(s[xx+1][yy]=='P') {s[xx+1][yy]='W';continue;}
			if(yy>=1) if(s[xx][yy-1]=='P') {s[xx][yy-1]='W';continue;}
			if(yy<m-1) if(s[xx][yy+1]=='P') {s[xx][yy+1]='W';continue;}
		}
	}
	int cpp=0;
	for(int i=0;i<n;i++){
		//cout<<s[i]<<endl;
		for(int j=0;j<m;j++){
			if(s[i][j]=='P') cpp++;
		}
	}
	cout<<cp-cpp<<endl;
}
