#include <stdio.h>
#include <string.h>
int main(){
	int f, n,sv[27]={0},ck[27]={0};
	char s[111],t[111],p[111],r[111];
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%s %s %s",s,t,p);
		int x=0,y=0,l =0,f = 0;
		while(1){
			//printf("%s - %s\n",s,r);
			if(strcmp(t,r)==0 && x == strlen(s)) break;
			if(s[x]==t[y]) {
				r[l] = s[x];
				y++;
				l++;
				x++;
				r[l]='\0';
				continue;
			}
			int ok = 0;
			for(int j = 0;j<strlen(p);j++){
				if(p[j]==t[y]){
					r[l]=p[j];
					p[j]='1';
					y++;
					l++;
					r[l] = '\0';
					ok = 1;
					break;
				}
			}
			if(!ok) f = 1;
			if(f) break;
		}
		printf("%s\n",(f==1)?"NO":"YES");
	}
	return 0;
}
