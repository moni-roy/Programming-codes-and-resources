#include <stdio.h>
long long int n,k,Ans=0;
void Main(){
	scanf("%lld%lld",&n,&k);
	long long int l=-1, r=n+1;
	while(r>l+1){
		long long int m = (l+r)/2;
		if((n-m)*(n-m+1)/2-m>k){
			l = m;
		}
		else r = m;
	}
	Ans = r;
	printf("%lld\n",Ans);
}
int main(){
	Main();
	return 0;
}
