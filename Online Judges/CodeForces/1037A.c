#include <stdio.h>
 
int main(){
	int n,k=1,Ans = 0;
	scanf("%d",&n);
	while(n>0){
		n-=k;
		k*=2;
		Ans++;
	}
	printf("%d\n",Ans);
	return 0;
}
