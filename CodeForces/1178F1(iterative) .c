#include <stdio.h>
#include <string.h>
#define MOD 998244353

int n, m, a[505];
long long store[505][505];

long long function(){
	for(int i = 1;i<=n;i++) store[i][i]=1;
	for(int seg = 1;seg<=n;seg++){
		for(int l = 1;l+seg<=n;l++){
			int r = l + seg;
			int id = l;
			for(int k = l;k<=r;k++){
				if(a[id]>a[k]){
					id = k;
				}
			}
			long long left = 0, right = 0;
			long long t = 1;
			for(int k = l;k<=id;k++){
				t = 1;
				if(l<k) t = (t * store[l][k-1])%MOD;
				if(k<id) t = (t*store[k][id-1])%MOD;
				left = (left + t)%MOD;
			}
			for(int k = id;k<=r;k++){
				t = 1;
				if(id<k) t = (t*store[id+1][k])%MOD;
				if(k<r) t = (t*store[k+1][r])%MOD;
				right = (right+t)%MOD;
			}
			store[l][r] = (left*right)%MOD;
		}
	}
	return store[1][n];
}
void solve(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= m; i++) scanf("%d",&a[i]);
	long long Ans  = function(1,m);
	printf("%lld\n",Ans);
}
int main(){
	solve();
	return 0;
}

