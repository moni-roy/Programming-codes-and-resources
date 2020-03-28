#include <stdio.h>
#define MOD 998244353 
long long a[200010], b[200010];

void merge(long long int *array,int l,int m,int r){
	int t[r-l+2];
	int i =l, j = m+1, k = 0;
	while (i<=m && j<=r) t[k++] = (array[i]<array[j])?array[i++]:array[j++];
	while (i<=m) t[k++] = array[i++];
	while (j<=r) t[k++] = array[j++];
	for(int i = l;i<=r; i++) array[i] = t[i-l];
}
void reverseMerge(long long int *array,int l,int m,int r){
	long long int t[r-l+2];
	int i =l, j = m+1, k = 0;
	while (i<=m && j<=r) t[k++] = (array[i]>array[j])?array[i++]:array[j++];
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
void reverseSort(long long int *array,int l,int r){
	if(l<r){
		int m = (l+r)/2;
		reverseSort(array,l,m);
		reverseSort(array,m+1,r);
		reverseMerge(array,l,m,r);
	}
}
void solve(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++) scanf("%lld", a+i);
	for(int i = 0;i<n;i++) scanf("%lld", b+i);
	sort(b,0,n-1);
	long long Ans = 0;
	for(int i = 0;i<n;i++){
		a[i] = a[i]*(i+1)*(n-i);
	}
	reverseSort(a,0,n-1);
	for(int i = 0;i<n;i++) Ans += (a[i]%MOD*b[i])%MOD, Ans%=MOD;
	printf("%lld\n", Ans);
}
int main(){
	solve();
	return 0;
}

