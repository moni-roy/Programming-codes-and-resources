vector<int>child[1000005];
int cnt[1000005];
queue<int>parent;
vector<int>Sort;
 
void topologicalSort(int n){
    int p;
    for(int i=1;i<=n;i++){
        if(!cnt[i]){
            parent.push(i);
        }
    }
    while(!parent.empty()){
        p=parent.front();
        for(int i=0;i<(int)child[p].size();i++){
            int cl=child[p][i];
            cnt[cl]--;
            if(!cnt[cl]){
                parent.push(cl);
            }
        }
        Sort.push_back(p);
        parent.pop();
    }
}
