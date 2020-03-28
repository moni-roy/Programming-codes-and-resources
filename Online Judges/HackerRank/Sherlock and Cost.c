#include <stdio.h>

int max(int a,int b){
	return (a>b)?a:b;
}
int abs(int a){
	return (a<0)?-a:a;
}
int main(){
	int t,n,a[100010],sv[100010][3];;
    scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i = 0;i<n;i++) sv[i][1]=sv[i][0] = 0;
		for(int i = 1;i<n;i++){
			sv[i][0] = max(sv[i][0],sv[i-1][1]+abs(a[i-1]-1)); // high -> low
			sv[i][1] = max(sv[i][1],sv[i-1][0]+abs(a[i]-1)); // low -> high
			sv[i][1] = max(sv[i][1],sv[i-1][1] +abs(a[i-1]-a[i])); // high -> high
		}
		printf("%d\n",max(sv[n-1][0],sv[n-1][1]));
	}
    return 0;
}
