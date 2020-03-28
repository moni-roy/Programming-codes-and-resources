#include <stdio.h>

int main(){
	int n,a[2100];
	scanf("%d",&n);
	for(int i = 0;i<n;i++) {
		scanf("%d",&a[i]);
		a[i]+=3e5;
	}
	printf("%d\n",n+1);
	printf("1 %d %d\n",n,(int)(3e5));
	for(int i = 0;i<n;i++){
		printf("2 %d %d\n",i+1,a[i]-i-1);
	}

	return 0;
}
