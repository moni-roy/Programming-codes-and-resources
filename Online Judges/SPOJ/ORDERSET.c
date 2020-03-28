#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define INF (1<<30)
typedef struct Trp{
    int key, priority ,size;
    struct Trp *left, *right;
}Treap; 
Treap *treap;
int Size(Treap *root){
    return root?root->size:0;
}
void updateSize(Treap *root){
    if(root) root->size = Size(root->right)+1+Size(root->left);
}
Treap *leftRotate(Treap *root){
    Treap *newRoot= root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    root = newRoot;
    updateSize(root->right);
    updateSize(root);
    return root;
}
Treap *rightRotate(Treap *root){
    Treap *newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    root = newRoot;
    updateSize(root->left);
    updateSize(root);
    return root;
}
Treap *New(int key){
    Treap *temp = (Treap*)malloc(sizeof (Treap));
    temp->key = key;
    temp->priority = rand();
    temp->size = 1;
    temp->left = temp->right = NULL;
    return temp;
}
Treap *insert(Treap *root, int key){
    if(root == NULL) return New(key);
    if(root->key > key){
        root->left = insert(root->left,key);
        if(root->left->priority > root->priority){
            root = leftRotate(root);
        }
    }
    else if(root->key < key){
        root->right = insert(root->right, key);
        if(root->priority < root->right->priority){
            root = rightRotate(root);
        }
    }
    updateSize(root);
    return root;
}
void valueInsert(int key){
    treap = insert(treap, key);
}
Treap *erase(Treap *root,int key){
    if(root == NULL) return root;
    if(key < root->key){
        root->left = erase(root->left, key);
    }
    else if(key>root->key){
        root->right = erase(root->right,key);
    }
    else{
        if(root->left == NULL){
            Treap *temp = root->right;
            free(root);
            root = temp;
        }
        else if(root->right == NULL){
            Treap *temp = root->left;
            free(root);
            root = temp;
        }
        else{
            if(root->left->priority > root->right->priority){
                root = leftRotate(root);
                root = erase(root,key);
            }
            else{
                root = rightRotate(root);
                root = erase(root, key);
            }
        }
    }
    updateSize(root);
    return root;
}
void delete(int key){
    treap = erase(treap, key);
}
int KTH(Treap *root, int kth){
    if(Size(root)<kth) return -INF;
    int sz = Size(root->left)+1;
    if(sz == kth) return root->key;
    if(kth<sz) return KTH(root->left,kth);
    return KTH(root->right, kth-sz);
}
int countSize(Treap *root, int key){
    if(root == NULL) return 0;
    if(key>root->key) return Size(root->left) + 1 + countSize(root->right,key);
    return countSize(root->left,key);
}
int main(){
    srand(time(NULL));
    int q,x;
    char ch[10];
    treap = NULL;
    scanf("%d", &q);
    while(q--){
        scanf("%s%d", ch, &x);
        if(ch[0] == 'I'){
            valueInsert(x);
        }
        else if(ch[0] == 'D'){
            delete(x);
        }
        else if(ch[0] == 'K'){
            int t = KTH(treap, x);
            if(t!=-INF) printf("%d\n",t);
            else printf("invalid\n");
        }
        else{
            printf("%d\n", countSize(treap,x));
        }
    }
    return 0;
}