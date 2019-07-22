#include <stdio.h>
#include <stdlib.h>

void solve(){
	int cnt = 0, n,a[111],half = 0, total = 0;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
		total+= a[i];
	}
	half = a[0];
	for(int i = 1;i<n;i++){
		if(a[i]*2<=a[0]){
			cnt ++;
			half += a[i];
		}
	}
	if(half*2<=total){
		puts("0");
	}
	else{
		printf("%d\n",cnt+1);
		printf("1");
		for (int i = 1; i < n; i++)
		{
			if(a[i]*2<=a[0]) printf(" %d",i+1);
		}
		puts("");
	}
}
int main(){
	solve();
	return 0;
}
