#include <stdio.h>
#define MXSZ 200002
int N,Q,A[MXSZ],M[MXSZ],E[MXSZ],id = 0;
typedef struct Node{
    int u;
    struct Node *next;
}node;
node *edge[MXSZ];
node *New(int a){
    node *t = (node*)malloc(sizeof(node));
    t->u = a;
    t->next = NULL;
    return t;
}
node *add(node* root, int a){
    node *t = New(a);
    if(root==NULL) return t;
    t->next = root;
    return t;
}
void init(){
    id = 0;
    for(int i = 0;i<MXSZ;i++) {
        edge[i]=NULL;
        M[i] = 0;
    }
}
void dfs(int u,int p){
    node *t = edge[u];
    M[u]=++id;
    while (t!=NULL)
    {
        int v = t->u;
        if(v!=p) dfs(v,u);
        t = t->next;
    }
    E[u] = id;
}
void MRoy(){
    init();
    scanf("%d%d",&N,&Q);
    for(int i = 1;i<N;i++){
        int a,b; scanf("%d %d",&a,&b);
        edge[a] = add(edge[a],b);
        edge[b] = add(edge[b],a);
    }
    dfs(1,-1);
    while (Q--){
        int p,x; scanf("%d%d",&p,&x);
        A[M[p]]+=x;
        A[E[p]+1]-=x;

    }
    for(int i = 1;i<=N;i++){
        A[i]+=A[i-1];
    }
    for(int i = 1;i<=N;i++){
        if(i!=1) printf(" ");
        printf("%d",A[M[i]]);
    }
    printf("\n");
    return;
}
int main(){
    MRoy();
    return 0;
}