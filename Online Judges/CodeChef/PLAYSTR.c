#include <stdio.h>

void solve(){
	int ts,l;
	scanf("%d",&ts);
	while (ts--)
	{
		char s[111],r[111];
		scanf("%d",&l);
		scanf("%s%s",s,r);
		int f = 0;
		for(int i = 0;i<l;i++){
			for(int j = i+1;j<l;j++){
				if(s[i]>s[j]){
					char c = s[i];
					s[i] = s[j];
					s[j] = c;
				}
			}
		}
		for(int i = 0;i<l;i++){
			for(int j = i+1;j<l;j++){
				if(r[i]>r[j]){
					char c = r[i];
					r[i] = r[j];
					r[j] = c;
				}
			}
		}
		for(int i = 0;i<l;i++){
			if(s[i]!=r[i]) f = 1;
		}
		if(f) puts("NO");
		else puts("YES");
	}
}
int main(){
	solve();
	return 0;
}

