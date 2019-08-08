#include <stdio.h>
#include <malloc.h>

#define MXSIZE 100009
const unsigned long long Base = 29;
int testCase,length, subLength;
char str[MXSIZE];
unsigned long long hash[MXSIZE],base[MXSIZE];

/* Set using BST */

typedef struct setStructure{
    unsigned long long key;
    struct setStructure *left, *right;
}Set;
Set *set; int Size = 0;
Set *New(unsigned long long key){
    Set *temp = (Set *)malloc(sizeof(Set));
    temp->key = key;
    temp->right = temp->left = NULL;
    return temp;
}
Set *insertRecursion(Set *root, unsigned long long key){
    if(root==NULL) {
        Size++;
        return New(key);
    }
    if(key < root->key) root->left = insertRecursion(root->left,key);
    else if(key>root->key) root->right = insertRecursion(root->right,key);
    return root;
}
void insert(unsigned long long key){
    set = insertRecursion(set,key);
}
void init(){
    base[0]=1ULL;
    for(int i = 1;i<MXSIZE;i++){
        base[i] = base[i-1]*Base;
    }
}
void computeHash(char *st, int len){
    hash[0]=0;
    for(int i = 1;i<=len;i++){
        hash[i] = hash[i-1]*Base + (st[i-1]-'a'+1);
    }
}
void Main(){
	init();
    scanf("%d",&testCase);
    while (testCase--){
        scanf("%d%d",&length, &subLength);
        scanf("%s",str);
        computeHash(str, length);
        set = NULL; Size = 0;
        for(int i = 0;i<=length-subLength;i++){
            unsigned long long sub = hash[i+subLength]-hash[i]*base[subLength];
			insert(sub);
        }
		printf("%d\n", Size);
    }
    return;
}
int main(){
    Main();
    return 0;
}
