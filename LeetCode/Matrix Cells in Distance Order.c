/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int abs(int x){
    if(x<0) return -x;
    return x;
}
int dis(int x,int y,int a,int b){
    return abs(x-a)+abs(y-b);
}

typedef struct st{
   int x,y;
    struct st *next;
}dt;

dt *add(dt *root, int x,int y){
    dt *tm = (dt *)malloc(sizeof(dt));
    tm->x = x;
    tm->y = y;
    tm->next = root;
    return tm;
}

int** allCellsDistOrder(int R, int C, int r0, int c0, int* returnSize, int** returnColumnSizes){
    int s = R*C;
    int **ret = (int**)malloc(sizeof(int*)*s);
    int *sizes = (int*)malloc(sizeof(int)*s);
    dt *in[s];
    for(int i = 0; i<s;i++){
        sizes[i] = 2;
        ret[i] = (int*)malloc(sizeof(int)*2);
        in[i] = NULL;
    }
    
    for(int i = 0;i<R;i++){
        for(int j = 0;j<C;j++){
            int d = dis(r0,c0, i,j);
            in[d] = add(in[d],i,j);
         //   printf("%d ",d);
        }
    }
    int id = 0;
    for(int i = 0;i<s;i++){
        dt *tm = in[i];
        while(tm!=NULL){
            ret[id][0] = tm->x;
            ret[id++][1] = tm->y;
            tm=tm->next;
        }
        
    }
    *returnSize = s;
    *returnColumnSizes = sizes;
    return ret;
}
