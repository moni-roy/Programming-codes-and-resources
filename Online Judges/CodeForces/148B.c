#include <stdio.h>
#include <stdlib.h>

void solve(){
	double vp,vd,t,f,c;
	scanf("%lf%lf%lf%lf%lf",&vp,&vd,&t,&f,&c);
	int Ans = 0;
	if(vp>=vd){
		puts("0");
		return;
	}
	double s1 = 0,s2 = 0;
	s1 = (double) vp*t;
	while(s1<c){
		s2 = s1/(vd-vp);
		s1 = s2*vd;
		if(s1>=c)  break;
		Ans ++;
		s1 = s1 + (s2+f)*vp;
	}
	printf("%d\n",Ans);
}
int main(){
	solve();
	return 0;
}
