#include <bits/stdc++.h>
using namespace std;
vector<int>node[210];

int BFS(int start_point){
	queue<int>temp_stored;
	temp_stored.push(start_point);
	int visit[1000]={0};
	visit[start_point]=1;
	while(!temp_stored.empty()){
		int from=temp_stored.front();
		for(int i=0;i<(int)node[from].size();i++){
			int to=node[from][i];
			if(!visit[to]){
				if(visit[from]==2){
					visit[to]=1;
				}
				else visit[to]=2;
				temp_stored.push(to);
			}
			if(visit[from]==visit[to]) return 0;
		}
		temp_stored.pop();
	}
	return 1;
}

int main(){
	int higest_number,inputs_number,first_point,second_point;
	while(cin>>higest_number&&higest_number){
		cin>>inputs_number;
		for(int i=0;i<inputs_number;i++){
			cin>>first_point>>second_point;
			node[first_point].push_back(second_point);
			node[second_point].push_back(first_point);
		}
		int check=BFS(0);
		if(check==1) puts("BICOLORABLE.");
		else puts("NOT BICOLORABLE.");
		for(int i=0;i<higest_number;i++){
			node[i].clear();
		}
	}
	return 0;
}
			
