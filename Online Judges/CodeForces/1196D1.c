#include <stdio.h>
int max(int a,int b){return (a>b)?a:b;}
int min(int a,int b){return (a<b)?a:b;}
int q,n,k;
char s[2002];
void Main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&n,&k);
		scanf("%s",s);
		char r[k+4],b[k+4],g[k+4];
		r[0] = 'R',r[1] = 'G',r[2]='B';
		b[0] = 'B',b[1] = 'R',b[2]='G';
		g[0] = 'G',g[1] = 'B',g[2]='R';
		for(int i = 3;i<=k;i+=3){
			r[i] = 'R',r[i+1] = 'G',r[i+2]='B';
			b[i] = 'B',b[i+1] = 'R',b[i+2]='G';
			g[i] = 'G',g[i+1] = 'B',g[i+2]='R';
		}
		r[k] = '\0'; b[k] = '\0'; g[k]='\0';
		int Ans = 1e9;
		for(int i = 0;i<=n-k;i++){
			int rc = 0,bc = 0, gc = 0;
			for(int j = 0;j<k;j++){
				if(s[i+j]!=r[j]) rc++;
				if(s[i+j]!=b[j]) bc++;
				if(s[i+j]!=g[j]) gc++;
			}
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
