#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	while(n--){

	long long a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	long long Ans = (a+b+c)/2;
	printf("%lld\n",Ans);
	}
	return 0;
}
