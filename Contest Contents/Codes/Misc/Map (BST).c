// Map implementation using BST, Not balanced BST
typedef struct mapStructure{
    int key, value;
    struct mapStructure *left, *right;
}Map;
Map *map;
Map *New(int key,int value){
    Map *temp = (Map *)malloc(sizeof(Map));
    temp->key = key;
    temp->value = value;
    temp->right = temp->left = NULL;
    return temp;
}
Map *insertRecursion(Map *root, int key,int value){
    if(root==NULL) {
        return New(key,value);
    }
    if(key < root->key) root->left = insertRecursion(root->left,key,value);
    else if(key>root->key) root->right = insertRecursion(root->right,key,value);
    else root->value = value;
    return root;
}
void insert(int key,int value){
    map = insertRecursion(map,key,value);
}
int findRecursion(Map *root, int key){
    if(root!=NULL) {
        if(key == root->key) return root->value;
        if(key<root->key) return findRecursion(root->left,key);
        return findRecursion(root->right,key);
    }
    return -1;
}
int find(int key){
    return (findRecursion(map,key)==-1)?0:1;
}
int getValue(int key){
    return findRecursion(map, key);
}
Map *minValue(Map *root){
    while (root->left!=NULL){
        root = root->left;
    }
    return root;
}
Map *eraseRecursion(Map *root, int key){
    if(root == NULL) return root;
    if(key<root->key) root->left = eraseRecursion(root->left,key);
    else if(key>root->key) root->right = eraseRecursion(root->right,key);
    else{
        if(root->left ==NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if(root->left == NULL){
            Map * temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Map * temp = root->left;
            free(root);
            return temp;
        }
        else{
            Map *temp = minValue(root->right);
            root->key = temp->key;
            root->right = eraseRecursion(root->right,temp->key);
        }
    }
    return root;
}
void erase(int key){
    map  = eraseRecursion(map, key);
}
int main(){
    insert(2,3);
    printf("%d\n",getValue(2));
    return 0;
}