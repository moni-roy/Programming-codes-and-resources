#include <stdio.h>
#include <string.h>

int l=0,k=0;
char s[1000100],fast[1000100],last[1000100];
void go(int x,int y){
	if(x>y) return;
	if(x==y){
		fast[l++] = s[x];
		return;
	}
	else if(s[x]==s[y]){
		fast[l++] = s[x];
		last[k++] = s[y];
	}
	else if(s[x]==s[y-1]){
		fast[l++] = s[x];
		if(y-1!=x) last[k++] = s[y-1];
		y--;
	}
	else if(s[x+1]==s[y]){
		fast[l++] = s[x+1];
		if(x+1!=y) last[k++] = s[y];
		x++;
	}
	go(x+1,y-1);
}

void solve(){
	scanf("%s",s);
	go(0,strlen(s)-1);
	for(int i = k-1;i>=0;i--) fast[l++] = last[i];
	fast[l]= '\0';
	puts(fast);
}
int main(){
	solve();
	return 0;
}

