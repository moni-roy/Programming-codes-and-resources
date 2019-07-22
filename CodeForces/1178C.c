#include <stdio.h>
#include <string.h>

long long modular(long long base,long long power,long long mod){
	long long result = 1;
	while (power)
	{
		if(power&1) result = (result * base)%mod;
		power>>=1;
		base = (base * base)%mod;
	}
	return result;
}

void solve(){
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	long long Ans = modular(2, a+b, 998244353);
	printf("%lld\n",Ans);
}
int main(){
	solve();
	return 0;
}

