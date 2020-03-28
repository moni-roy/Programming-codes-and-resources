#include <bits/stdc++.h>
using namespace std;
#define INF (1<<30)
struct TreapNode{
    int value,size,prio;
    TreapNode *left, *right;
    TreapNode(){
        value = 0;
        prio = 0;
        size = 0;
        left=right= NULL;
    }   
    TreapNode(int _value){
        value = _value;
        prio = rand();
        size = 1;
        left=right= NULL;
    }
};
struct Treap{
    TreapNode *treap;
    Treap(){
        treap = NULL;
        srand(time(NULL));
    }
    int Size(TreapNode* root){
        return (root!=NULL)?root->size:0;
    }
    void updateSize(TreapNode* &root){
        if(root) root->size = 1+Size(root->left) + Size(root->right);
    }
    void leftRotate(TreapNode* &root){
        TreapNode *temp = root->left;
        root->left = temp->right;
        temp->right = root;
        root = temp;
        updateSize(root->right);
        updateSize(root);
    }
    void rightRotate(TreapNode* &root){
        TreapNode *temp = root->right;
        root->right = temp->left;
        temp->left = root;
        root = temp;
        updateSize(root->left);
        updateSize(root);
    }
    void insert(TreapNode* &root, int value){
        if(root == NULL ) {
            root = new TreapNode(value);
            return;
        }
        if(root->value > value){
            insert(root->left, value);
            if(root->prio < root->left->prio){
                leftRotate(root);
            }
        }
        else if(root->value < value){
            insert(root->right,value);
            if(root->prio < root->right->prio){
                rightRotate(root);
            }
        }
        updateSize(root);
    }
    void erase(TreapNode* &root, int value){
        if(root == NULL) return;
        if(root->value < value) erase(root->right, value);
        else if(root->value > value) erase(root->left, value);
        else{
            if(root->left && root->right){
                if(root->left->prio > root->right->prio){
                    leftRotate(root);
                }
                else rightRotate(root);
                erase(root, value);
            }
            else{
                TreapNode *temp = root;
                if(root->left) root = root->left;
                else root = root->right;
                delete temp;

            }
        }
        updateSize(root);
    }
    void insert(int key){
        insert(treap, key);
    }
    void erase(int key){
        erase(treap,key);
    }
    int KTH(TreapNode* root,int kth){
        if(Size(root)<kth) return -INF;
        int sz = Size(root->left)+1;
        if(sz== kth) return root->value;
        if(sz < kth) return KTH(root->right, kth-sz);
        return KTH(root->left, kth);
    }
    int KTH(int kth){
        return KTH(treap, kth);
    }
    int countSize(TreapNode *root, int value){
        if(root==NULL) return 0;
        if(root->value < value) return 1+Size(root->left) + countSize(root->right, value);
        return countSize(root->left, value);
    }
    int countSize(int value){
        return countSize(treap,value);
    }
};
int main(){
    int q;scanf("%d",&q);
    int x;
    char ch[10];
    Treap oTreap;
    while (q--){
        scanf("%s%d",ch, &x);
        if(ch[0] == 'I'){
            oTreap.insert(x);
        }
        else if(ch[0]=='D'){
            oTreap.erase(x);
        }
        else if(ch[0]=='K'){
            int t = oTreap.KTH(x);
            if(t==-INF) puts("invalid");
            else printf("%d\n", t);
        }
        else{
            printf("%d\n",oTreap.countSize(x));
        }
    }
    
    return 0;
}