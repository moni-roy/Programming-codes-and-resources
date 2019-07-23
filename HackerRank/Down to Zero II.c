#include <stdio.h>
#include <string.h>
const int MX = 1000010;
void solve(){
	int q, store[MX],n;

	for(int i = 0;i<MX;i++) store[i] = -1;
	store[0]=0;store[1] = 1; store[2] = 2; store[3] = 3;

	for(int i = 1;i<MX;i++){
		if(store[i]==-1 || store[i]>(store[i-1]+1)) store[i] = store[i-1]+1;

		for(int j = 1;j<=i && j*i<MX;j++){
			if(store[i*j]==-1|| store[i*j]>store[i]+1) store[i*j] = store[i]+1;
		}
	}

	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		printf("%d\n",store[n]);
	}
}
int main(){
	solve();
	return 0;
}

