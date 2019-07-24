#include <stdio.h>
int min(int a,int b){
	return (a<b)?a:b;
}
int t[1001],n,k,c;
int main(){
	scanf("%d%d",&n,&k);
	for(int i = 0;i<n;i++){
		scanf("%d",&c);
		t[c]++;
	}
	int count = 0,Ans = 0;
	for(int i = 1;i<=k;i++){
		if(count*2>n) break;
		int can = t[i]/2;
		can = min(can,(n+1)/2-count);
		count+=can;
		Ans+=(can*2);
		t[i] = t[i]-can*2;
	}
	if(count<(n+1)/2){
		Ans += ((n+1)/2 - count);
	}
	printf("%d\n",Ans);
	return 0;
}
