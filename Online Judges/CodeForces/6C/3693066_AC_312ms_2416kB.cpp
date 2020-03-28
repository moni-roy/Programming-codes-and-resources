#include <bits/stdc++.h>
using namespace std;
int n,a[100010];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1) {
		cout<<n<<" 0"<<endl;
		return 0;
	}
	int i=0,j=n-1,ca=1,cb=1;
	int at=a[i];
	int bt=a[j];
	while(i<j){
		if(i+1==j){
			 break;
		 }
		if(at==bt){
			i++;
			j--;
			if(i==j) {
				ca++;
				break;
			}
			at+=a[i];
			bt+=a[j];
			ca++;
			cb++;
		}
		else if(at<bt){
			i++;
			at+=a[i];
			ca++;
		 }
		else if(bt<at) {
			j--;
			bt+=a[j];
			cb++;
		}
	}
	cout<<ca<<" "<<cb<<endl;
}
