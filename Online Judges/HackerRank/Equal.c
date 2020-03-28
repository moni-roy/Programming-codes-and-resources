#include <stdio.h>

void merge(int *a,int l,int m,int r){
	int t[r-l+1];
	int i = l,j = m+1, k = 0;
	while (i<=m && j<=r)
	{
		if(a[i]<=a[j]) t[k++]=a[i++];
		else t[k++]=a[j++];
	}
	while (i<=m) t[k++]=a[i++];
	while (j<=r) t[k++]=a[j++];
	for(i = l;i<=r;i++) a[i]=t[i-l];
}
void sort(int *a, int l,int r){
	if (l<r)
	{
		int m = (l+r)/2;
		sort(a,l,m);
		sort(a,m+1,r);
		merge(a,l,m,r);
	}	
}
int ok(int *a, int n){
	int ret = 1e9;
	for(int i = 0;i<3;i++){
		int res = 0;
		for(int j =0;j<n;j++){
			int t = a[j]-a[0] + i;
			res += (t/5),t%=5;
			res += (t/2),t%=2;
			res += t;
		}
		ret = (ret<res)?ret:res;
	}
	return ret;
}
int main(){
	int t,n,a[100010];
    scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,0,n-1);
		printf("%d\n",ok(a,n));
	}
    return 0;
}
