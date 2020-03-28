#include <stdio.h>
#include <string.h>
#include <malloc.h>
int main(){
	int n,m,q,row[100010],column[100010];
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&n,&m);
		char **s = (char **)malloc((n+1)*sizeof(char *));
		for(int j = 0;j<n+1;j++) s[j] = (char *)malloc((m+1)*sizeof(char));
		for(int i = 0;i<n;i++){
			row[i] = 0;
		}
		for(int i = 0;i<m;i++){
			column[i] = 0;
		}
		for(int i = 0;i<n;i++) {
			scanf("%s",s[i]);
			for(int j = 0;j<m;j++){
				row[i]+= (s[i][j]=='*')?1:0;
				column[j]+=(s[i][j]=='*')?1:0;
			}
		}
		int Ans = 1e9;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				if(s[i][j]=='*'){
					Ans = (Ans>(n+m-row[i]-column[j]))?(n+m-row[i]-column[j]):Ans;
				}
				else{
					Ans = (Ans>(n+m-row[i]-column[j]-1))?(n+m-row[i]-column[j]-1):Ans;
				}
			}
		}
		printf("%d\n",Ans);
	}
	return 0;
}
