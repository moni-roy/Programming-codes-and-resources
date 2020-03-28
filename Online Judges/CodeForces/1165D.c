#include <stdio.h>

void merge(long long int *array,int l,int m,int r){
	long long int t[r-l+2];
	int i =l, j = m+1, k = 0;
	while (i<=m && j<=r) t[k++] = (array[i]<array[j])?array[i++]:array[j++];
	while (i<=m) t[k++] = array[i++];
	while (j<=r) t[k++] = array[j++];
	for(int i = l;i<=r; i++) array[i] = t[i-l];
}
void sort(long long int *array,int l,int r){
	if(l<r){
		int m = (l+r)/2;
		sort(array,l,m);
		sort(array,m+1,r);
		merge(array,l,m,r);
	}
}
int ok(long long int *a, int sz, long long n){
	long long int t[sz+2],k = 0;
	for(long long i = 2; i*i <= n;i++){
		if(n%i == 0){
			t[k++] = i;
			if(i!=n/i) t[k++] = n/i;
		}
		if(k>sz) return 0;
	}
	sort(t,0,sz-1);
	for(int i = 0;i<sz;i++) if(a[i]!=t[i]) return 0;
	return 1;
}
void solve(){
	int ts,n;
	long long a[303];
	long long Ans = 0;
	scanf("%d",&ts);
	while(ts--){
		scanf("%d",&n);
		for(int i = 0;i<n;i++) scanf("%lld",a+i);
		sort(a,0,n-1);
		Ans = a[0]*a[n-1];
		if(ok(a,n,Ans)) printf("%lld\n", Ans);
		else puts("-1");
	}
}
int main(){
	solve();
	return 0;
}

