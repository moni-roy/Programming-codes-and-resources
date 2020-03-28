#include <stdio.h>

void solve(){
	int n,x,y;
	char s[200010];
	scanf("%d%d%d",&n,&x,&y);
	scanf("%s",s);
	int Ans = 1;
	for(int i = n-1;i>=n-y;i--){
		if(s[i]=='1') Ans++;
	}
	if(s[n-y-1]=='0') Ans++;
	for(int i = n-y-2;i>=n-x;i--){
		if(s[i]=='1') Ans++;
	}
	printf("%d\n",Ans-1);
}
int main(){
	solve();
	return 0;
}

