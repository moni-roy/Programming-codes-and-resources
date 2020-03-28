#include <stdio.h>
#include <string.h>
long long max(long long x,long long y){
	return (x>y)?x:y;
}
int n,a[100010],b[100010];
long long store[100010][3],Ans;

long long go(int p,int f){
	if(p>=n) return 0;
	if(store[p][f]!=-1) return store[p][f];
	long long ret = go(p+1,0);
	if(!f){
		ret = max(ret, a[p]+go(p+1,1));
		ret = max(ret, b[p]+go(p+1,2));
	}else if(f==1){
		ret = max(ret, b[p]+go(p+1,2));
	}else{
		ret = max(ret, a[p]+go(p+1,1));
	}
	return store[p][f] = ret;
}
void Main(){
	scanf("%d",&n);
	for(int i = 0;i<n ; i++) scanf("%d",a+i);
	for(int i = 0;i<n ; i++) scanf("%d",b+i);
	memset(store, -1, sizeof(store));
	Ans = go(0,0);
	printf("%lld\n",Ans);
}
int main(){
	Main();
	return 0;
}
