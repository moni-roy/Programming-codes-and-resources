#include <stdio.h>

int q,b,w;
void Main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&b,&w);
		if(b>3*w+1 || w>3*b+1) puts("NO");
		else{
			puts("YES");
			if(b>w){
				int x = 2, y =2;
				while(w>0){
					if((x+y)&1) b--;
					else w--;
					printf("%d %d\n",x,y);
					y++;
				}
				x = 1;
				int exy = y;
				y = 2;
				while(y<=exy && b>0){
					if((x+y)&1) {
						b--;
						printf("%d %d\n",x,y);
					}
					y++;
				}
				x = 3;
				y = 2;
				while(y<=exy && b>0){
					if((x+y)&1) {
						b--;
						printf("%d %d\n",x,y);
					}
					y++;
				}
				if(b>0){
					printf("2 1\n");
					b--;
				}
				if(b>0){
					printf("2 %d\n",exy);
					b--;
				}
			}
			else{
				w = w^b;
				b = w^b;
				w = w^b;
				int x = 2, y = 3;
				while(w>0){
					if((x+y)&1) w--;
					else b--;
					printf("%d %d\n",x,y);
					y++;
				}
				x = 1;
				int exy = y;
				y = 3;
				while(y<=exy && b>0){
					if((x+y)%2==0) {
						b--;
						printf("%d %d\n",x,y);
					}
					y++;
				}
				x = 3;
				y = 3;
				while(y<=exy && b>0){
					if((x+y)%2==0) {
						b--;
						printf("%d %d\n",x,y);
					}
					y++;
				}
				if(b>0){
					printf("2 2\n");
					b--;
				}
				if(b>0){
					printf("2 %d\n",exy);
					b--;
				}
			}
		}
	}
	return ;
}
int main(){
	Main();
	return 0;
}
