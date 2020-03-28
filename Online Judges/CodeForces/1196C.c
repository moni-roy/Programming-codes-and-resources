#include <stdio.h>
int max(int a,int b){return (a>b)?a:b;}
int min(int a,int b){return (a<b)?a:b;}
int q,n;
void Main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		int l = -1e5, r = 1e5;
		int d = -1e5, u = 1e5;
		int x,y,f1,f2,f3,f4;
		for(int i = 0;i<n;i++) {
			scanf("%d%d%d%d%d%d",&x,&y,&f1,&f2,&f3,&f4);
			if(!f1) l = max(l,x);
			if(!f2) u = min(u,y);
			if(!f3) r = min(r,x);
			if(!f4) d = max(d,y);
		}
		if(l>r || u<d) puts("0");
		else{
			printf("1 %d %d\n",(l+r)/2, (d+u)/2);
		}
	}
	return ;
}
int main(){
	Main();
	return 0;
}
