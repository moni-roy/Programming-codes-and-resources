#include <stdio.h>

long long min(long long a,long long b){return (a<b)?a:b;}
typedef struct mk
{
	int x,y,w;
}roy;
roy edges[200010];
void merge(roy *edge, int l,int m,int r){
	roy tp[ r-l+2];
	int i = l, j = m+1, k = 0;
	while(i<=m && j<=r) tp[k++]=(edge[i].w<edge[j].w)?edge[i++]:edge[j++];
	while(i<=m) tp[k++] = edge[i++];
	while(j<=r) tp[k++] = edge[j++];
	for(int p = l;p<=r;p++) edge[p] = tp[p-l];
}
void sortStuct(roy *edge, int l,int r){
	if(l<r){
		int m = (l+r)/2;
		sortStuct(edge,l,m);
		sortStuct(edge,m+1,r);
		merge(edge,l,m,r);
	}
}

void mergeArray(long long *ok, int l,int m,int r){
	long long tp[r-l+2];
	int i = l, j = m+1, k = 0;
	while(i<=m && j<=r) tp[k++]=(ok[i]<ok[j])?ok[i++]:ok[j++];
	while(i<=m) tp[k++] = ok[i++];
	while(j<=r) tp[k++] = ok[j++];
	for(int p = l;p<=r;p++) ok[p] = tp[p-l];
}
void sortArray(long long *ok, int l,int r){
	if(l<r){
		int m = (l+r)/2;
		sortArray(ok,l,m);
		sortArray(ok,m+1,r);
		mergeArray(ok,l,m,r);
	}
}

int mp[200010],id = 0,n,m,k,x,y,w;
long long dis[1001][1001];
long long Ans[1000100];
void Main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 0;i<m;i++){
		scanf("%d%d%d",&x,&y,&w);
		edges[i].w = w;
		edges[i].y = y;
		edges[i].x = x;
	}
	sortStuct(edges,0,m-1);
	for(int i = 0;i<1000;i++) for(int j = 0;j<1000;j++) if(i!=j) dis[i][j] = 1e13;
	for(int i = 0;i<min(m,k);i++){
		x = edges[i].x;
		y = edges[i].y;
		w = edges[i].w;
		if(mp[x]==0) mp[x]=++id;
		if(mp[y]==0) mp[y]=++id;
		x = mp[x];
		y = mp[y];
		dis[x][y] = w;
		dis[y][x] = w;
	}
	for(int p = 0;p<=id;p++){
		for(int i = 0;i<=id;i++){
			for(int j = 0;j<=id;j++){
				dis[i][j] = min(dis[i][j],dis[i][p]+dis[p][j]);
			}
		}
	}
	int p = 0;
	for(int i = 0;i<=id;i++){
		for(int j = 0;j<i;j++){
			Ans[p++] = dis[i][j];
		}
	}
	sortArray(Ans,0,p-1);
	printf("%lld\n", Ans[k-1]);
}
int main(){
	Main();
	return 0;
}
