#include <stdio.h>
#include <malloc.h>
int sesh = 10009;
typedef struct mk
{
	int choto,boro;
	struct mk *tarpor;
	
}ok;
ok* Amk(int _,int __){
	ok *tmp = (ok*)malloc(sizeof(ok));
	tmp->choto = (_<__)?_:__;
	tmp->boro = (_>__)?_:__;
	tmp->tarpor = NULL;
	return tmp;
}
typedef struct mkroy
{
	int value;
	struct mkroy *tarpor;
	
}roy;
roy *join(roy *head, int value){
	roy *tmp = (roy*)malloc(sizeof(roy));
	tmp->value = value;
	tmp->tarpor = NULL;
	if(head==NULL) return tmp;
	tmp->tarpor = head;
	return tmp;
}
ok* add(ok *matha,int a,int b){
	ok *tm = Amk(a,b);
	if(matha==NULL){
		return tm;
	}
	tm->tarpor = matha;
	return tm;
}
int joma[10009];

void utano(int jayga,int koto){
	jayga++;
	while (jayga<sesh)
	{
		joma[jayga]+=koto;
		jayga += (jayga & (-jayga));
	}
}
int dao(int jayga){
	int uttor = 0;
	jayga++;
	while (jayga)
	{
		uttor+=joma[jayga];
		jayga -= (jayga & (-jayga));
	}
	return uttor;
}

/* New Style BIT */
void update(int p, int v){
	for(;p<sesh; p |= (p+1)){
		joma[p]+=v;
	}
}
int query(int p){
	int ret = 0;
	for(;p>=0; p = (p&(p+1))-1){
		ret+=joma[p];
	}
	return ret;
}
int main(){
	int n, x1, x2, y1, y2;
	long long uttor = 0;
	ok *soya[10009],*khara[10009];
	roy *visited[10009];
	for(int i = 0;i<10009;i++){
		soya[i]=NULL;
		khara[i]=NULL;
		visited[i]=NULL;
	}
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		x1+=5000,x2+=5000,y1+=5000,y2+=5000;
		if(y1==y2){
			soya[y1] = add(soya[y1],x1,x2);
		}
		else{
			khara[x1] = add(khara[x1],y1,y2);
		}
	}
	for(int y = 0;y<sesh;y++){
		ok *sya = soya[y];
		while (sya!=NULL)
		{
			for(int  i = 0;i<sesh;i++) {
				joma[i]=0;
				visited[i]=NULL;
			}
			int bam = sya->choto; 
			int dan = sya->boro;
			for(int x = bam;x<=dan;x++){
				ok *kra = khara[x];
				while (kra!=NULL)
				{
					int down = kra->choto;
					int up = kra->boro;
					if(down<=y && up>y){
						utano(x,1);
						visited[up] = join(visited[up],x);
					}
					kra = kra->tarpor;
				}	
			}
			for(int Y = y+1;Y<sesh;Y++){
				ok *sy = soya[Y];
				while (sy!=NULL)
				{
					int l = sy->choto;
					int r = sy->boro;
					int ferot = dao(r)-dao(l-1);
					uttor += (ferot * (ferot-1)/2);
					sy = sy->tarpor;
				}
				roy *tmp = visited[Y];
				while (tmp!=NULL)
				{
					utano(tmp->value,-1);
					tmp=tmp->tarpor;
				}	
			}
			sya = sya->tarpor;
		}	
	}
	printf("%lld\n",uttor);
	return 0;
}
