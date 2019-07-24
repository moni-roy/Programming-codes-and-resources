#include <stdio.h>
#include <string.h>
#define MOD 998244353
int max(int x,int y){
	return (x>y)?x:y;
}
int n;
long long a[100010],b[100010],digit[100010],Ans = 0;
int digitCount(long long t){
	int dgt = 0;
	while(t){
		dgt++;
		t/=10;
	}
	return dgt;
}
long long first(long long p,int y){
	long long ret = 0;
	int x = digitCount(p),pos = 0;

	for(int i = 0;i<max(x,y);i++){
		if(i<y){
			pos++;
		}
		if(i<x){
			ret += ((p%10)*b[pos])%MOD;
			ret%=MOD;
			p/=10;
			pos++;
		}
	}
	return ret;
}
long long second(int x, long long p){
	long long ret = 0;
	int y = digitCount(p),pos = 0;

	for(int i = 0;i<max(x,y);i++){
		if(i<y){
			ret += ((p%10)*b[pos])%MOD;
			ret%=MOD;
			p/=10;
			pos++;
		}
		if(i<x){
			pos++;
		}
	}
	return ret;
}
void Main(){
	b[0] = 1;
	for(int i = 1;i<20;i++) b[i] = (b[i-1]*10)%MOD;
	scanf("%d",&n);
	for(int i = 0;i<n ; i++) {
		scanf("%lld",a+i);
		digit[digitCount(a[i])]++;
	}
	for(int i = 0;i<n;i++){
		int t = digitCount(a[i]);
		for(int d = 1;d<11;d++){
			long long ret = first(a[i],d);
			Ans = (Ans + (ret*digit[d])%MOD)%MOD;
			ret = second(d,a[i]);
			Ans = (Ans + (ret*digit[d])%MOD)%MOD;
		}
	}
	printf("%lld\n",Ans);
}
int main(){
	Main();
	return 0;
}
