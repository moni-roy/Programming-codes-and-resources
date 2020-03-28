/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** queensAttacktheKing(int** queens, int queensSize, int* queensColSize, int* king, int kingSize, int* returnSize, int** returnColumnSizes){
    int X = king[0];
    int Y = king[1];
    
    int arr[10][10],sv[10][10];
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            sv[i][j] = 0;
        }
    }
    for(int i = 0;i<queensSize;i++){
        int x = queens[i][0];
        int y = queens[i][1];
        sv[x][y] = 1;
    }
    
    for(int i = X;i<8;i++) {
        if(sv[i][Y]) {
            sv[i][Y]++;
            break;
        }
    }
    for(int i = X;i>=0;i--) {
        if(sv[i][Y]) {
            sv[i][Y]++;
            break;
        }
    }
    
    for(int i = Y;i<8;i++) {
        if(sv[X][i]) {
            sv[X][i]++;
            break;
        }
    }
    for(int i = Y;i>=0;i--) {
        if(sv[X][i]) {
            sv[X][i]++;
            break;
        }
    }
       
    for(int i = X, j = Y; i>=0 && j>=0; i--,j--) {
        if(sv[i][j]) {
            sv[i][j]++;
            break;
        }
    }
    for(int i = X, j = Y; i<8 && j<8; i++,j++) {
        if(sv[i][j]) {
            sv[i][j]++;
            break;
        }
    }
    for(int i = X, j = Y; i>=0 && j<8; i--,j++) {
        if(sv[i][j]) {
            sv[i][j]++;
            break;
        }
    }
    for(int i = X, j = Y; i<8 && j>=0; i++,j--) {
        if(sv[i][j]) {
            sv[i][j]++;
            break;
        }
    }
    
    int **ret = (int**)malloc(queensSize*sizeof(int*));
    //*returnColumnSizes = (int*)malloc(sizeof(int)*queensSize);
    int *retC = (int*)malloc(sizeof(int)*queensSize);
    
    for(int i = 0;i<queensSize;i++) ret[i] = (int*)malloc(2*sizeof(int));
    
    int sz = 0;
    
    for(int i = 0;i<queensSize;i++){
        int x = queens[i][0];
        int y = queens[i][1];
        
        if(sv[x][y]==2) {
            // returnColumnSizes[0][sz] = 2;
            retC[sz] = 2;
            ret[sz][0] = queens[i][0];
            ret[sz++][1] = queens[i][1];    
            //printf("%d %d %d\n", sz, ret[sz-1][0],ret[sz-1][1]);
        }
    }
    *returnSize = sz;
    *returnColumnSizes = retC;
    return ret;
}
