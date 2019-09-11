#include <malloc.h>
#include <stdio.h>

#define MX 1000001
typedef struct Node {
    int u;
    struct Node *next;
} node;
node *edge[MX+2], *cur;
node *New(int a) {
    node *temp = (node *)malloc(sizeof(node));
    temp->next = NULL;
    temp->u = a;
    return temp;
}
node *add(node *root, int a) {
    node *temp = New(a);
    if (root == NULL) return temp;
    temp->next = root;
    return temp;
}
int min(int a, int b) {
    return (a < b) ? a : b;
}
int max(int a, int b) {
    return (a < b) ? b : a;
}
int notHash(int a, int b) {
    int id = min(a, b) * 1000 + max(a, b);
    return id;
}
int n, a, b, in[MX];
void init() {
    for (int i = 0; i <= MX; i++) {
        in[i] = 0;
        edge[i] = NULL;
    }
    cur = NULL;
}
void MRoy() {
    init();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        for (int j = 0; j < n - 2; j++) {
            scanf("%d", &b);
            int u = notHash(i, a);
            int v = notHash(i, b);
            edge[u] = add(edge[u], v);
            a = b;
            in[v]++;
        }
    }
    int times = 0;
    for (int i = 1; i <= MX; i++) {
        if (in[i] == 0) {
            cur = add(cur, i);
            times++;
        }
    }
    int days = 0, total = 0;
    while (times) {
        days++;
        total += times;
        int t = 0;
        node *after = NULL;
        while(cur!=NULL){
            int u = cur->u;
            node *tm = edge[u];
            while (tm != NULL) {
                int v = tm->u;
                in[v]--;
                if (in[v] == 0) {
                    after = add(after, v);
                    t++;
                }
                tm = tm->next;
            }
            cur = cur->next;
        }
        cur = after;
        times = t;
    }
    if (total == MX) {
        printf("%d\n", days);
    } else
        printf("-1\n");
}
int main() {
    MRoy();
    return 0;
}