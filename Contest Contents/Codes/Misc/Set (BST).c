// Set implementation using BST, Not balanced BST
typedef struct setStructure{
    int key;
    struct setStructure *left, *right;
}Set;
Set *set; int Size = 0;
Set *New(int key){
    Set *temp = (Set *)malloc(sizeof(Set));
    temp->key = key;
    temp->right = temp->left = NULL;
    return temp;
}
Set *insertRecursion(Set *root, int key){
    if(root==NULL) {
        Size++;
        return New(key);
    }
    if(key < root->key) root->left = insertRecursion(root->left,key);
    else if(key>root->key) root->right = insertRecursion(root->right,key);
    return root;
}
void insert(int key){
    set = insertRecursion(set,key);
}
int findRecursion(Set *root, int key){
    if(root!=NULL) {
        if(key == root->key) return 1;
        if(key<root->key) return findRecursion(root->left,key);
        return findRecursion(root->right,key);
    }
    return 0;
}
int find(int key){
    return findRecursion(set,key);
}
Set *minValue(Set *root){
    while (root->left!=NULL){
        root = root->left;
    }
    return root;
}
Set *eraseRecursion(Set *root, int key){
    if(root == NULL) return root;
    if(key<root->key) root->left = eraseRecursion(root->left,key);
    else if(key>root->key) root->right = eraseRecursion(root->right,key);
    else{
        if(root->left ==NULL && root->right == NULL) {
            Size--;
            free(root);
            return NULL;
        }
        else if(root->left == NULL){
            Set * temp = root->right;
            Size--;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Set * temp = root->left;
            Size--;
            free(root);
            return temp;
        }
        else{
            Set *temp = minValue(root->right);
            root->key = temp->key;
            root->right = eraseRecursion(root->right,temp->key);
        }
    }
    return root;
}
void erase(int key){
    set  = eraseRecursion(set, key);
}