#include <stdio.h>
#include <stdlib.h>
typedef struct mk{
    int u;
    struct mk *next;
}roy; 
roy *adj[1000010];
int vs[1000010],Ans[1000010],id = 0;
roy* add(roy* root, int v){
    roy *temp = (roy *)malloc(sizeof(roy));
    temp->next=NULL;
    temp->u = v;
    if(root==NULL) return temp;
    temp->next = root;
    return temp;
}
int f = 0;
int sort(int u){
    roy *temp = adj[u];
    vs[u] = 1;
    while ( temp!=NULL){
        int v = temp->u;
        temp = temp->next;
        if(vs[v]==0){
            if(sort(v)) return 1;
        }
        else if(vs[v]==1){
            return 1;
        }
    }
    Ans[id++] = u;
    vs[u]=2;
    return 0;
}
void Main(){
    int n,m,u,v;
    while(scanf("%d%d",&n,&m)==2){
        id = f= 0;
        if(n==0 && m==0) break;
        int i;
        for(i = 1;i<=n;i++){
            adj[i]=NULL;
        }
        for( i = 0;i<m;i++){
            scanf("%d %d",&u,&v);
            adj[u] = add(adj[u],v);
        }
        
        for( i = 1;i<=n;i++) vs[i] = 0;
        for( i = 1;i<=n;i++){
            if(vs[i]==0)
                f |= sort(i);
        }
        if(id==n && f==0){
            for( i = n-1;i>=0;i--){
                printf("%d\n",Ans[i]);
            }
        }
        else puts("IMPOSSIBLE");
    }
    return;
}
int main(){
    Main();
    return 0;
}