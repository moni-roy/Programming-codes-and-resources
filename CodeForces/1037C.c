#include <stdio.h>
#include <stdlib.h>

void solve(){
	int n,Ans = 0;
	scanf("%d",&n);
	char *a = (char *)malloc((n+1)*sizeof(char));
	char *b = (char *)malloc((n+1)*sizeof(char));
	scanf("%s%s",a,b);
	for(int i = 0;i<n-1;i++){
		if(a[i]!=b[i]){
			if((a[i+1]!=b[i+1]) && (a[i+1]==b[i] && a[i]==b[i+1])) {
				a[i+1]=b[i+1];
				Ans++;
			}
			else Ans++;
		}
	}
	if(a[n-1]!=b[n-1]) Ans++;
	printf("%d\n",Ans);
}

int main(){
	solve();
	return 0;
}
