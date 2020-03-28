#include <bits/stdc++.h>
using namespace std;
int main(){
	int ts,cs=0;
	string st;
	int matrix[130][130];
	int xx,yy,x,y,m,n;
	cin>>ts;
	while(ts--){
		memset(matrix, 0,sizeof matrix);
		cin>>xx>>yy;
		cin>>st;
		int ln=st.size();
		int cnt=0;
		matrix[xx][yy]=1;
		m=xx;n=yy;
		for(int i=0;i<ln;i++){
			if(st[i]=='R') {
				cnt++;
				cnt%=4;
				}
			else if(st[i]=='L'){
				cnt--;
				cnt+=4;
				cnt%=4;
			}
			else{
				
				if(cnt==0){
					x=m+0;
					y=n+1;
				}
				else if(cnt==1){
					x=m+1;
					y=n+0;
				}
				else if(cnt==2){
					x=m+0;
					y=n-1;
				}
				else
				{
					x=m-1;
					y=n;
				}
				
				matrix[x][y]++;
				m=x;
				n=y;
			}
		}
		int dble=0;
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				if(matrix[i][j]>1){
					dble++;
				}
			}
		}
		cout<<"Case #"<<++cs<<": "<<m<<" " <<n<<" "<<dble<<endl;
	}
	return 0;
}
