#include <stdio.h>

void merge(int *a, int l, int m, int r){
	int t[r-l+2];
	int i = l,j = m+1, k = 0;
	while(i<=m && j<=r) t[k++] = (a[i]<a[j])?a[i++]:a[j++];
	while(i<=m) t[k++] = a[i++];
	while(j<=r) t[k++] = a[j++];
	for(int i = l;i<=r;i++) a[i] = t[i-l];
}
void sort(int *a,int l,int r){
	if(l<r){
		int m = (l+r)/2;
		sort(a,l,m);
		sort(a,m+1,r);
		merge(a,l,m,r);
	}
}
void solve(){
	int n,a[200010];
	scanf("%d",&n);
	for(int i = 0;i<n;i++) scanf("%d",a+i);
	sort(a,0,n-1);
	int Ans = 1;
	for(int i = 0;i<n;i++){
		if(a[i]>=Ans) Ans++;
	}
	printf("%d\n",Ans-1);
}
int main(){
	solve();
	return 0;
}

