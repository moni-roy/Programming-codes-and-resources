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
