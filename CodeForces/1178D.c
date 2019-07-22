#include <stdio.h>

int isPrime(int n){
	for(int i  = 2;i*i<=n;i++){
		if(n%i==0) return 0;
	}
	return 1;
}
void solve(){
	int n;
	scanf("%d",&n);
	if(isPrime(n)){
		printf("%d\n",n);
		for(int i = 1;i<n;i++){
			printf("%d %d\n",i,i+1);
		}
		printf("%d %d\n", 1, n);
	}
	else{
		int k = n;
		while (!isPrime(n)) n++;
		printf("%d\n",n);
		for(int i = 1;i<k;i++){
			printf("%d %d\n",i,i+1);
		}
		printf("%d %d\n",k,1);
		for(int i = k;i<n;i++){
			printf("%d %d\n",i-k+1, i-k+1+k/2);
		}
	}
}
int main(){
	solve();
	return 0;
}

