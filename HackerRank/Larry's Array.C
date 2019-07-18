//https://www.cs.bham.ac.uk/~mdr/teaching/modules04/java2/TilesSolvability.html
#include <stdio.h>

int main(){
	int t,n,a[1001],Ans;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		Ans = 0;
		for(int i = 0;i<n;i++) scanf("%d",&a[i]);
		for(int i = 0;i<n;i++){
			for(int j = i+1;j<n;j++){
				if(a[i]>a[j]) Ans++;
			}
		}
		printf("%s\n",(Ans%2)?"NO":"YES");
	}
	return 0;
}
