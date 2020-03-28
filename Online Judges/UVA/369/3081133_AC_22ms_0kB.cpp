#include <bits/stdc++.h>
using namespace std;
double ans,n,m,i,j,mx;
int main(){
	while(cin>>n>>m&&n&&m)
	{
		ans=1;
		mx=max(m,n-m);
		for(i=n,j=1;i>mx;i--,j++){
			ans/=j;
			ans*=i;
		}
		printf("%.0lf things taken %.0lf at a time is %.0lf exactly.\n",n,m,ans);
	}
	return 0;
}
