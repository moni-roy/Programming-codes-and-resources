#include <stdio.h>
#include <stdlib.h>

typedef struct mk
{
	int node;
	struct mk *next;
}roy;
roy *add(roy *head, int node){
	roy *tm = (roy*)malloc(sizeof(roy));
	tm->node = node;
	tm->next = NULL;
	if(head==NULL) return tm;
	tm->next = head;
	return tm;
}
void merge(int *array,int l,int m,int r){
	int tm[r-l+1];
	int i = l,j = m+1,k = 0;
	while (i<=m && j<=r) tm[k++] = (array[i]<array[j])?array[i++]:array[j++];
	while (i<=m) tm[k++] = array[i++];
	while (j<=r) tm[k++] = array[j++];
	for(int i = l;i<=r;i++ ) array[i] = tm[i-l];	
}
void mergeSort(int *array,int l,int r){
	if(l<r){
		int m = (l+r)/2;
		mergeSort(array,l,m);
		mergeSort(array,m+1,r);
		merge(array,l,m,r);
	}
}

void solve(){
	int n,u,v;
	scanf("%d",&n);
	int *a = (int*)calloc(n+1, sizeof(int));
	int *one = (int*)malloc((n+1)*sizeof(int));
	int *two = (int*)malloc((n+1)*sizeof(int));
	roy **graph = (roy**)calloc(n+1, sizeof(roy*));
	for(int i = 0;i<n-1;i++){
		scanf("%d%d",&u,&v);
		graph[u] = add(graph[u],v);
		graph[v] = add(graph[v],u);
	}
	for(int i = 0;i<n;i++){
		scanf("%d",a+i);
	}
	int *lv = (int*) calloc(n+1,sizeof(int));
	lv[1]=1;
	int front = 0, rear = 0;
	front++;
	int f = 0,k = 0;
	while (rear<front)
	{
		int u = a[rear++];
		roy *t = graph[u];
		int child = 0;
		while (t!=NULL)
		{
			int v = t->node;
			if(lv[v]==0){
				lv[v]=lv[u]+1;
				two[child] = a[front+child];
				one[child++] = v;
			}
			t = t->next;
		}
		if(child){
			mergeSort(one,0,child-1);
			mergeSort(two,0,child-1);
			int i = 0;
			for(;i<child;i++){
				if(one[i]!=two[i]) break;
			}
			if(i<child) break;
			front+=child;
		}
	}
	if(front<n) puts("NO");
	else puts("YES");
}
int main(){
	solve();
	return 0;
}
