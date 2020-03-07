/*
 * This soultion for binary string
 * */
const int MX = 20000010;
int idx = 0;
struct trie{
	int nd[5];
	trie(){
		for(int i=0;i<5;i++) nd[i] = -1;
	}
}tri[MX];
void insert(int parent,int child,int value){
	for(int i=31;i>=0;i--){
		for(int j=0;j<2;j++){
			tri[child].nd[j]=tri[parent].nd[j];
		}
		int val = 0;
		if(value & (1<<i)) val = 1;
		tri[child].nd[val] = ++idx;
		child = tri[child].nd[val]; 
		parent = tri[parent].nd[val]; 
	}
}
