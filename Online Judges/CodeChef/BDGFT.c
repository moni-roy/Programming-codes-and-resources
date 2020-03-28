#include <stdio.h>
#include <string.h>

char s[100010];
void solve(){
	int ts;
	scanf("%d",&ts);
	while (ts--)
	{
		scanf("%s",s);
		int Ans = 0;
		int ln = strlen(s);
		for(int i = 1; (i*i + i)<= ln;i++){
			int k = i*i+i;
			int front = 0,rear = 0;
			long long one = 0,zero = 0;
			for(int x = 0; x <ln;x++){
				if(front<k-1) {
					if(s[front++] =='1') one++;
				}
				else if(front ==k-1){
					if(s[front++] =='1') one++;
					zero  = k-one;
					if(zero == one*one) {
						Ans++;
					}
				}
				else{
					if(s[rear++] == '1') one--;
					if(s[front++]=='1') one++;
					zero  = k-one;
					if(zero == one*one) {
						Ans++;
					}
				}
			}
		}
		printf("%d\n",Ans);
	}
}
int main(){
	solve();
	return 0;
}

