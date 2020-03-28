#include <stdio.h>
#include <stdlib.h>
typedef struct mk{
    int u;
    struct mk *next;
}roy; 
roy **adj;
int *Ans,id = 0;
roy* add(roy* root, int v){
    roy *temp = (roy *)malloc(sizeof(roy));
    temp->next=NULL;
    temp->u = v;
    if(root==NULL) return temp;
    temp->next = root;
    return temp;
}
int *ok,n, queue[1001001],front =0,rear = 0;
roy *temp;
void sort(){
    int i;
    for( i = 1;i<=n;i++){
        if(ok[i]==0) {
            queue[rear++]=i;
        }
    }
    while(rear>front){
        int u = queue[front++];
        Ans[id++] = u;
        temp = adj[u];
        while (temp!=NULL)
        {
            int v = temp->u;
            temp = temp->next;
            ok[v]--;
            if(ok[v]==0){
                queue[rear++] = v;
            }
        }
    }
}
void init(){
    adj = (roy**)malloc((n+1)*sizeof(roy*));
    Ans = (int*)malloc(sizeof(int)*(n+1));
    ok = (int*)malloc(sizeof(int)*(n+1));
    int i;
    for(i = 1;i<=n;i++){
        adj[i]=NULL;
        ok[i] = 0;
    }
}
void Main(){
    int m,u,v;
    while(scanf("%d%d",&n,&m)==2){
        if(n==0 && m==0) break;
        id = rear = front=0;
        int i;
        init();
        for( i = 0;i<m;i++){
            scanf("%d %d",&u,&v);
            adj[u] = add(adj[u],v);
            ok[v]++;
        }
        sort();
        if(id==n){
            for( i = 0;i<n;i++){
                printf("%d\n",Ans[i]);
            }
        }
        else puts("IMPOSSIBLE");
        for( i = 1;i<=n;i++){
            roy *p = adj[i];
            while( p != NULL ){
                adj[i] = adj[i]->next;
                free(p);
                p = adj[i];
            }
        }
    }
    return;
}
int main(){
    Main();
    return 0;
}