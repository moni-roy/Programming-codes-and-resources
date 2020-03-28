#include <stdio.h>
int abs(int a){
	return (a<0)?-a:a;
}
void merge(int *a,int l,int m,int r){
	int t[r-l+1];
	int i = l,j = m+1,k=0;
	while(i<=m && j<=r) t[k++] = (a[i]<=a[j])?a[i++]:a[j++];
	while(i<=m) t[k++] = a[i++];
	while(j<=r) t[k++] = a[j++];
	for(int i  = l;i<=r;i++) a[i] = t[i-l];
}
void sort(int *a, int l,int r){
	if(l<r){
		int m = (l+r)/2;
		sort(a,l,m);
		sort(a,m+1,r);
		merge(a,l,m,r);
	}
}
int main(){
	int n,a[200010],s;
	scanf("%d%d",&n,&s);
	for(int i = 0; i<n ;i++){
		scanf("%d",&a[i]);
	}
	sort(a,0,n-1);
	long long int Ans = 0;
	if(a[n/2]<s){
		for(int i = n/2;i<n;i++){
			if(a[i]<s) Ans += s-a[i];
		}
	}
	else if(a[n/2]>s){
		for(int i = n/2;i>=0;i--){
			if(a[i]>s) Ans += a[i]-s;
		}
	}
	printf("%lld\n",Ans);
	return 0;
}
