#include <stdio.h>
int max(int a,int b){return (a>b)?a:b;}
int min(int a,int b){return (a<b)?a:b;}
int q,n,k;
char s[200002],r[200002],b[200002],g[200002];
void Main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&n,&k);
		scanf("%s",s);
		for(int i = 0;i<n;i+=3){
			r[i] = 'R',r[i+1] = 'G',r[i+2]='B';
			b[i] = 'B',b[i+1] = 'R',b[i+2]='G';
			g[i] = 'G',g[i+1] = 'B',g[i+2]='R';
		}
		r[n] = '\0'; b[n] = '\0'; g[n]='\0';
		int Ans = 1e9;
		int rc = 0,bc = 0, gc = 0;
		for(int i = 0;i<k;i++){
			if(s[i]!=r[i]) rc++;
			if(s[i]!=b[i]) bc++;
			if(s[i]!=g[i]) gc++;
		}
		Ans = min(Ans,min(rc,min(bc,gc)));
		for(int i = k;i<n;i++){
			if(s[i]!=r[i]) rc++;
			if(s[i]!=b[i]) bc++;
			if(s[i]!=g[i]) gc++;
			if(s[i-k]!=r[i-k]) rc--;
			if(s[i-k]!=b[i-k]) bc--;
			if(s[i-k]!=g[i-k]) gc--;
			Ans = min(Ans,min(rc,min(bc,gc)));	
		}
		printf("%d\n",Ans);
	}
	return ;
}
int main(){
	Main();
	return 0;
}
