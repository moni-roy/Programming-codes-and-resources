#include <stdio.h>
#include <malloc.h>
#include <string.h>
struct mk
{
	int jayga;
	char s[11];
	struct mk *tarpor;
}*gor[101],*asol[101];

struct mk *pichone(struct mk *aiche, int kothay, char ki[11]){
	struct mk *tm = (struct mk*)malloc(sizeof(struct mk));
	tm->jayga = kothay;
	strcpy(tm->s,ki);
	if(aiche==NULL) return tm;
	while(aiche->tarpor!=NULL){
		aiche = aiche->tarpor;
	}
	aiche->tarpor = tm;
	return aiche;
}

int main(){
	int n, a, mx = 0;
	char s[11];
	for(int i = 0;i<101;i++) {
		gor[i]=NULL;
		asol[i]=NULL;
	}
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d %s",&a, s);
		gor[a] = pichone(gor[a],i+1,s);
		if(asol[a]==NULL) asol[a]= gor[a];
		if(a>mx) mx = a;
	}
	for(int i = 0;i<=mx;i++){
		struct mk *emni = asol[i];
		while (emni!=NULL)
		{
			if((emni->jayga)*2<=n) printf("-");
			else printf("%s",emni->s);
			emni = emni->tarpor;
		}
	}
	return 0;
}
