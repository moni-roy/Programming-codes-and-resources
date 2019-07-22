#include <stdio.h>
#include <string.h>

char s[1001001];
long long Ans = 0;
void solve(){
	scanf("%s",s);
	long long cnt = 0, wow = 0;
	for(int i = 0;s[i]!='\0';i++){
		if(s[i]=='v' && s[i+1]=='v') {
			cnt++;
			Ans += wow;
		}
		else if(s[i]=='o'){
			wow += cnt;
		}
	}
	printf("%lld\n",Ans);
}
int main(){
	solve();
	return 0;
}

