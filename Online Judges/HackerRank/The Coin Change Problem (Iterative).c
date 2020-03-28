#include <stdio.h>

long long sv[255], a[55], n, m;

int main(){
    scanf("%lld%lld",&n,&m);    
    for(int i = 0;i<m;i++){
        scanf("%lld",&a[i]);
    }
    sv[0]= 1;
	for(int i = 0;i<m;i++){
		for(int j = a[i];j<=n;j++){
			sv[j] += sv[j-a[i]];
		}
	}
    long long int Ans = sv[n];
    printf("%lld\n",Ans);
    return 0;
}
