/*
 * https://www.hackerrank.com/contests/w25/challenges/stone-division
 * 
 * Solution: Just find Grandy Value among all cut
 * */
map<ll,int> sv;
ll a[15],m,n;
ll grandy(ll pile){
	if(pile<=1) return 0;
	if(sv.count(pile)) return sv[pile];
	set<int>st;
	for(int i=0;i<m;i++){
		if(pile%a[i]){}
		else{
			if(a[i]%2){
				st.insert(grandy(pile/a[i]));
			}
			else st.insert(0);
		}
	}
	int mn = 0;
	for(auto x: st){
		if(mn!=x) break;
		mn++;
	}
	return (sv[pile]=mn);
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++) cin>>a[i];
	ll Ans = grandy(n);
	if(Ans) cout<<"First"<<endl;
	else cout<<"Second"<<endl;
	return 0;
}

