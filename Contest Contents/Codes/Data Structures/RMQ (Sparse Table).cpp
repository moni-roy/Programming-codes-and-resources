int M[100200][25],a[100020],n,l,r;
void sparseTableMin(){
	for(int i=0;i<n;i++) M[i][0]=i;
	for(int j=1;1<<j<=n;j++){
		for(int i=0;i+(1<<(j-1))<n;i++){
			if(a[M[i][j-1]]<=a[M[i+(1<<(j-1))][j-1]]) M[i][j]=M[i][j-1];
			else M[i][j]= M[i+(1<<(j-1))][j-1];
		}
	}
}
int RMQMin(int x,int y){
	int  k = log2(y-x+1);
	//~ int k = 31 - __builtin_clz(y-x+1);
	int i=x,j=y;
	if(a[M[i][k]]<=a[M[j-(1<<k)+1][k]]) return M[i][k];
	return M[j-(1<<k)+1][k];
}
