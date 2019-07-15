#include <stdio.h>
 
int main(){
	int n,k,ts;
	scanf("%d",&ts);
	for(int i = 0;i<ts;i++){
		scanf("%d %d", &n,&k);
		if(k%3)
		{
			printf("%s\n",(n%3)?"Alice":"Bob");
		}
		else{
			n = n%(k+1);
			printf("%s\n",(n%3 || n==k)?"Alice":"Bob");
		}
	}
	return 0;
}
