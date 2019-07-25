#include <stdio.h>

int q,n,k,a[200010],odd = 0;
void Main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&n,&k);
		odd = 0;
		for(int i = 0;i<n;i++) {
			scanf("%d",a+i);
			if(a[i]&1) odd++;
		}
		if(odd>=k && (k-odd)%2==0){
			puts("YES");
			for(int i = 0;i<n;i++){
				if(k==1) break;
				if(a[i]&1) {
					printf("%d ",i+1);
					k--;
				}
			}
			printf("%d\n",n);
		}
		else puts("NO");
	}
	return ;
}
int main(){
	Main();
	return 0;
}
