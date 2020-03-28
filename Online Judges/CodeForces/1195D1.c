#include <stdio.h>
#include <string.h>
#define MOD 998244353
int n;
long long a[100010],b[100010],Ans;
long long function(long long x){
	int pos = 0;
	long long ret = 0;
	while (x)
	{
		long long r = x%10;x/=10;
		ret += (b[pos*2+1]*r)%MOD;ret%=MOD;
		ret += (b[pos*2]*r)%MOD; ret%=MOD;
		pos++;
	}
	return ret%MOD;
}
void Main(){
	b[0] = 1;
	for(int i = 1;i<20;i++) b[i] = (b[i-1]*10)%MOD;
	scanf("%d",&n);
	for(int i = 0;i<n ; i++) scanf("%lld",a+i);
	for(int i = 0;i<n;i++){
		Ans += (n*function(a[i]))%MOD;
		Ans %= MOD;
	}
	printf("%lld\n",Ans);
}
int main(){
	Main();
	return 0;
}
