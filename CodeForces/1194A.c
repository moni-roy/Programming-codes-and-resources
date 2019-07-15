#include <stdio.h>
#include <string.h>
#include <malloc.h>
int main(){
	int n,m,q;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&n,&m);
		printf("%d\n",m*2);
	}
	return 0;
}
