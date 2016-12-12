struct trie{
	int cnt;
	trie *nd[30];
	trie(){
		cnt = 0;
		for(int i=0;i<30;i++) nd[i]=NULL;
	}
	~trie(){
		for(int i=0;i<30;i++) {
			if(nd[i]!=NULL){
				delete nd[i];
			}
		}
	}
};
int build(string s,trie *rt){
	rt->cnt=0;
	for (int i = 0; i < (int)s.size(); i += 1){
		int p=s[i]-'a';
		if(rt->nd[p]==NULL){
			rt->nd[p]=new trie();
			rt->nd[p]->cnt=0;
		}
		if(i==s.size()-1){
			rt->nd[p]->cnt++;
			return (rt->nd[p]->cnt);
		}
		rt=rt->nd[p];
	}
}
int main(){
	trie *rt=new trie();
	cin>>s;
	int ans=build(s,rt);
	delete rt;
}
