#include <stdio.h>
#include <string.h>

void solve(){
	int n;
	char s[200010];
	scanf("%d",&n);
	scanf("%s",s);
	char r[200010];
	int k = 0;
	for(int i = 0;s[i+1]!='\0';){
		if(s[i]!=s[i+1]){
			r[k++] = s[i++];
			r[k++] = s[i++];
		}
		else{
			i++;
		}
	}
	if(k%2){
		k--;
	}
	r[k] = '\0';
	printf("%d\n",strlen(s) - k );
	puts(r);
}
int main(){
	solve();
	return 0;
}

