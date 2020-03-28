#include <stdio.h>
#include <string.h>
#define MOD 998244353

int n, m, a[505];
long long store[505][505];

long long go(int l,int r){
	if(l>n || r<1 || l>r) return 1;
	if(store[l][r]!=-1) return store[l][r];
	store[l][r] = 0;
	int color = l;
	for(int k = l;k<=r;k++) if(a[k]<a[color]) color = k;
	long long left = 0,right = 0;
	for(int k = l;k<=color;k++){
		left += go(l,k-1)*go(k,color-1);
		left%=MOD;
	}
	for(int k = color;k<=r;k++){
		right += go(color+1,k)*go(k+1,r);
		right%=MOD;
	}
	return store[l][r] = (left*right)%MOD;
}
void solve(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= m; i++) scanf("%d",&a[i]);
	memset(store, -1, sizeof(store));
	long long Ans  = go(1,m);
	printf("%lld\n",Ans);
}
int main(){
	solve();
	return 0;
}

