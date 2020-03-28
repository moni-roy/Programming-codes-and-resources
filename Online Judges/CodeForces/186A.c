#include <stdio.h>
#include <stdlib.h>

void solve(){
	char a[1000010],b[1000010];
	scanf("%s%s",a,b);
	int l1 = strlen(a);
	int l2 = strlen(b);
	if(l1!=l2){
		printf("NO\n");
	}
	else{
		int count = 0;
		for(int i = 0;i<l1;i++){
			if(a[i]!=b[i]){
				count++;
			}
			if(count>2) break;
		}
		if(!(count%2)){
			int i = 0,j = l1-1;
			while(i<j){
				if(a[i]==b[i]) i++;
				if(a[j]==b[j]) j--;
				if(a[i]!=b[i] && a[j]!=b[j]) break;
			}
			if(a[i]==b[j] && a[j]==b[i]) puts("YES");
			else puts("NO");
		}
		else puts("NO");
	}
}
int main(){
	solve();
	return 0;
}
