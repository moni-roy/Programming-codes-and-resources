#include <bits/stdc++.h>
using namespace std;

struct mk{
    int p;
    string s;
    mk *n;
} *h[101],*tp[101];

mk *add(mk *hd, int c, string k)
{
    mk *tm = (mk *)malloc(sizeof(mk));
    tm->p = c;
    tm->s = k;
    if(hd==NULL)  {
		return tm;
	}
    while (hd->n!=NULL)
    {
        hd = hd->n;
    }
    hd->n = tm;
    return hd;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,a;
    string s;
    
    for(int i = 0;i<101;i++) {
		h[i]=NULL;
		tp[i]=NULL;
	}
    
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a>>s;
        h[a] = add(h[a],i+1,s);
        if(tp[a]==NULL) tp[a] = h[a];
    }
    for(int i = 0;i<101;i++){
        while(tp[i]!=NULL){
            if((tp[i]->p)*2<=n) cout<<"- ";
            else cout<<tp[i]->s <<" ";
            tp[i]= tp[i]->n;
        }
    }
    return 0;
}
