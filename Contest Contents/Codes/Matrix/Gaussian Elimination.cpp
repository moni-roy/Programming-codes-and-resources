char ss[100];
struct frac{
	ll a,b;
	frac() { a=0; b=1; }
	frac(ll _a, ll _b){
		a=_a; b=_b;
		reduce();
	}
	frac operator + (const frac &p) const{
		ll ra= a*p.b + p.a*b;
		ll rb = b*p.b;
		return frac(ra,rb);
	}
	frac operator - (const frac &p) const{
		ll ra= a*p.b - p.a*b;
		ll rb = b*p.b;
		return frac(ra,rb);
	}
	frac operator * (const frac &p) const{
		ll ra=  p.a*a;
		ll rb = b*p.b;
		return frac(ra,rb);
	}
	frac operator / (const frac &p) const{
		ll ra= a*p.b ;
		ll rb = b*p.a;
		return frac(ra,rb);
	}
	bool operator == (const frac &p) const{
		return a*p.b==p.a*b;
	}
	bool operator < (const frac &p) const{
		return a*p.b < p.a*b;
	}
	frac ABS(){
		return frac(abs(a),abs(b));
	}
	void print(){
		if (a==0) cout<<0;
		else if(b==1) cout<<a;
		else cout<<a<<"/"<<b;
	}
	void read(){
		scanf("%s",ss);
		bool flg=0;
		for(int i=0;ss[i] && !flg;i++){
			if(ss[i]=='/') flg=1;
		}
		if(flg){
			sscanf(ss,"%lld/%lld",&a,&b);
		}
		else{
			sscanf(ss,"%lld",&a);
			b=1;
		}
		reduce();
	}
	void reduce(){
		ll g=gcd(a,b);
		a/=g;
		b/=g;
		if(a==0) b=1;
		if(b<0) a=-a,b=-b;
	}
};
const frac ZERO = frac(0,1);
frac ar[55][55],res[55];
void fun(){
	for(int i=1,j=1;i<=n&&j<=m;){
		int idx=i;
		for(int k=i+1;k<=m;k++){
			if(!(ar[k][j]==ZERO)){
				idx=k;
				break;
			}
		}
		if(!(ar[idx][j]==ZERO)){
			for(int x=1;x<=n+1;x++){
				swap(ar[i][x],ar[idx][x]);
			}
			for(int x=1;x<=m;x++){
				if(x!=i){
					for(int y=j+1;y<=n+1;y++)
					{
						ar[x][y]=ar[x][y]-ar[i][y]*(ar[x][j]/ar[i][j]);
					}
					ar[x][j]=ZERO;
				}
			}
			i++;
		}
		j++;
	}
	int rank=0;
	for(int i=1;i<=m;i++){
		bool zr=1;
		for(int j=1;j<=n;j++){
			if(!(ar[i][j]==ZERO)){
				zr=0;
				break;
			}
		}
		if(zr && !(ar[i][n+1]==ZERO)){
			rank=-1;
			break;
		}
	}
	if(rank>=0){
		for(int i=1,j=1;i<=m&&j<=n;){
			if(!(ar[i][j]==ZERO)){
				res[j]=ar[i][n+1]/ar[i][j];
				rank++;
				i++;
			}
			j++;
		}
	}
	if(rank==-1) puts("No Solution.");
	else if(rank<n){
		cout<<"Infinitely many solutions containing "<<n-rank<<" arbitrary constants."<<endl;
	}
	else{
		for(int i=1;i<=n;i++){
			cout<<"x["<<i<<"] = ";
			res[i].print();
			cout<<endl;
		}
	}
	return;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n+1;j++){
			ar[i][j].read();
		}
	}
	cout<<"Solution for Matrix System # "<<ts<<endl;
	fun();
	return 0;
}
