/*
 * nCr mod M (May Not Prime).cxx
 * called function by "bin::binomial(n,r,mod);
 */
namespace crt{
	ll extendedEuclid(ll a,ll b, ll &x,ll &y){
		if(a == 0){
			x = 0;
			y = 1;
			return b;
		}
		ll x1,y1;
		ll d = extendedEuclid(b%a , a, x1, y1);
		x = y1 - (ll)(b/a) * x1;
		y = x1;
		return d;
	}
	ll modinv(ll n,ll m){
		ll x,y;
		ll gd = extendedEuclid(n, m, x, y);
		if(gd != 1) return 0;
		return (x+m)%m;
	}
	ll CRT(vector<ll>ar,vector<ll>mds){
		ll ret = 0, lc = 1;
		int n = ar.size();
		for(ll i = 0; i < n; i++) lc *= mds[i];
		for(ll i = 0; i < n; i++){
			ll tmp = ar[i] * (lc / mds[i]);
			tmp %= lc;
			tmp = (tmp * modinv(lc/mds[i],mds[i]))%lc;
			ret += tmp;
			ret %= lc;
		}
		return (ret+lc)%lc;
	}
}
// nCr
namespace bin{
	ll sv[MX];
	ll mod;
	ll trailing(ll a,ll b){
		ll ret = 0;
		while(a){
			a/=b;
			ret+=a;
		}
		return ret;
	}
	ll bmod(ll p,ll e,ll m){
		ll ret = 1;
		while(e){
			if(e&1) ret = (ret*p)%m;
			e>>=1;
			p = (p*p)%m;
		}
		return ret;
	}
	ll fact(ll a,ll b){
		ll ret = bmod(sv[mod-1],a/mod,mod);
		if(a>=b) ret = (ret * fact(a/b,b))%mod;
		return (ret*sv[a%mod])%mod;
	}
	ll binomial(ll n,ll r,ll x,ll y){
		if(r>n) return 0;
		if(n==r || r==0) return 1;
		for(int i=0,mod=1;i<y;++i) mod *= x;
		ll t = trailing(n,x) - trailing(r,x) - trailing(n-r,x);
		if(t>=y) return 0;
		sv[0]=1;
		for(int i=1;i<mod;++i){
			sv[i]=sv[i-1]*((i%x)?i:1)%mod;
		}
		ll ret = fact(n,x) * bmod((fact(r,x)*fact(n-r,x))%mod, (mod/x)*(x-1)-1,mod)%mod;
		while(t--) ret *= x,ret%=mod;
		return ret;
	}
	
	ll binomial(ll n,ll r,ll m){
		if(r>n || m==1) return 0;
		if(n==r || r==0) return 1;
		vector<pair<int,int> > fcts; 
		for(ll i=2;i*i<=m;++i){
			int cnt = 0;
			while(m%i==0){
				m/=i;
				cnt++;
			}
			if(cnt) fcts.push_back({i,cnt});
		}
		if(m>1) fcts.push_back({m,1});
		vector<ll>ar,mds;
		for(int i=0;i<(int)fcts.size();++i){
			ll t = 1;
			for(int j=0;j<fcts[i].second;++j){
				t *= fcts[i].first;
			}
			mds.push_back(t);
			ar.push_back(binomial(n,r,fcts[i].first,fcts[i].second));
		}
		return crt::CRT(ar,mds);
	}
}

