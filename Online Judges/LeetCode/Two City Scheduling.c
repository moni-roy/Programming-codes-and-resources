int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
    
    for(int i = 0;i<costsSize;i++){
        for(int j = i+1;j<costsSize;j++){
            if( (costs[i][0]-costs[i][1]) > (costs[j][0]-costs[j][1]) ){
                int x = costs[i][0];
                int y = costs[i][1];
                
                costs[i][0] = costs[j][0];
                costs[i][1] = costs[j][1];
                costs[j][0] = x;
                costs[j][1] = y;
            }
        }
    }
    
    int mid = costsSize/2;
    int ret = 0;
    for(int i = 0;i<costsSize;i++){
        if(i<mid) ret += costs[i][0];
        else ret += costs[i][1];
    }
    return ret;
    
}
