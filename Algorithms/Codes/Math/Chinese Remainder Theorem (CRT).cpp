ll modinv(ll n,ll m){
    ll x,y;
    ll gd = extendedEuclid(n, m, x, y);
    if(gd != 1) return 0;
    return (x+m)%m;
}
ll CRT(ll a[],ll m[],ll n){
    ll ret = 0, lc = 1;
    for(ll i = 0; i < n; i++) lc *= a[i];
    for(ll i = 0; i < n; i++){
        ll tmp = m[i] * (lc / a[i]);
        tmp %= lc;
        tmp = (tmp * modinv(lc/a[i],a[i]))%lc;
        ret += tmp;
        ret %= lc;
    }
    return (ret+lc)%lc;
}
