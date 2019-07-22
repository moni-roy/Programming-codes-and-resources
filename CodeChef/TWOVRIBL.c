#include <stdio.h>
#include <math.h>

void solve(){
	int ts;
	scanf("%d",&ts);
	while (ts--)
	{
		long long int n;
		scanf("%lld",&n);
		long long int x = 0,y = 0,Ans = 0;
		while(x<=n){
			long long t = sqrt((double)y)+1;
			x = t;
			y += (t*t);
			Ans++;
		}
		printf("%lld\n",Ans-1);
	}
}
int main(){
	solve();
	return 0;
}

