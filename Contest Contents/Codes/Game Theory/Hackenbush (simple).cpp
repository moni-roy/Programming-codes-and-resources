/*
 * g[] for adjacent list of Graph
* */
vector<int>g[505];
int hackenbush(int x,int pr=-1) {
    int ret=0;
    for(int i=0; i<(int)g[x].size(); i++) {
        int y = g[x][i];
        if(pr!=y) {
            ret ^= (1 + hackenbush(y,x));
        }
    }
    return ret;
}
