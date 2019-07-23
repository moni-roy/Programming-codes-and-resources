#include <stdio.h>

typedef struct mk
{
	int day,type;
}roy;

int n,m,a[200010],l,r,tot=0;
roy off[200010];

int ok(int days){
	int t[n+1];
	int need = 0,collect = days;
	for(int i = 0;i<n;i++) t[i] = a[i];
	for(int i = m-1;i>=0;i--){
		if(off[i].day>days) continue;
		collect = (collect<=off[i].day)?collect:off[i].day;
		int tp = (collect<=t[off[i].type-1])?collect:t[off[i].type-1];
		need += tp;
		t[off[i].type-1]-= tp;
		collect-=tp;
	}
	need += (tot - need)*2;
	return (need<=days);
}
void merge(roy *of, int s,int m,int e){
	roy tmp[e-s+2];
	int i = s,j = m+1,k = 0;
	while (i<=m && j<=e) tmp[k++] = (of[i].day<of[j].day)?of[i++]:of[j++];
	while (i<=m) tmp[k++] = of[i++];
	while (j<=e) tmp[k++] = of[j++];
	for(int i = s;i<=e;i++) of[i] = tmp[i-s];
}
void sort(roy *of, int s,int e){
	if(s<e){
		int m = (e+s)/2;
		sort(of,s,m);
		sort(of,m+1,e);
		merge(of,s,m,e);
	}
}
void solve(){
	scanf("%d%d",&n,&m);
	for(int i = 0;i<n;i++){
		scanf("%d",a+i);
		tot += a[i];
	}
	for(int i = 0;i<m;i++){
		scanf("%d%d",&off[i].day,&off[i].type);
	}
	sort(off, 0, m-1);
	l = 1;r = tot*2+1;
	int Ans;
	while (l<=r)
	{
		int m = (l+r)/2;
		if(ok(m)){
			Ans  = m;
			r = m-1;
		}
		else l = m+1;
	}
	printf("%d\n",Ans);
}
int main(){
	solve();
	return 0;
}

