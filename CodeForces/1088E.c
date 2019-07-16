#include <stdio.h>
#include <stdlib.h>

typedef struct mk
{
	int v;
	struct  mk *next;
}roy;
roy *add(roy *head,int v){
	roy *t = (roy*)malloc(sizeof(roy));
	t->v = v;
	t->next =NULL;
	if(head==NULL) return t;
	t->next = head;
	return t;
}
long long n,a[300010],s[300030],u,v,count;
roy *gp[300030];

void dfs(int x,int p){
	s[x]+= a[x];
	roy* t = gp[x];
	while (t!=NULL)
	{
		int y = t->v;
		if(y!=p){
			dfs(y,x);
			if(s[y]>0) s[x]+=s[y];
		}
		t=t->next;
	}
}
void go(int x,int p,long long total){
	s[x]+= a[x];
	roy* t = gp[x];
	while (t!=NULL)
	{
		int y = t->v;
		if(y!=p){
			go(y,x,total);
			if(s[y]>0) s[x]+=s[y];
		}
		t=t->next;
	}
	if(s[x]==total) s[x]= 0, count++;
}
int main(){
	for(int i = 0;i<300030;i++) gp[i]=NULL;
	scanf("%lld",&n);
	for(int i = 1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<n;i++){
		scanf("%lld%lld",&u,&v);
		gp[u] = add(gp[u],v);
		gp[v] = add(gp[v],u);
	}
	dfs(1,-1);
	long long  mx = -1e18;
	for(int i = 1;i<=n;i++) {
		mx = (mx<s[i])?s[i]:mx;
		s[i] = 0;
	}
	go(1,-1,mx);
	printf("%lld %lld\n",mx*count, count);
	return 0;
}
