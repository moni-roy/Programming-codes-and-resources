#define Base1 10000019LL
#define Base2 10000079LL
#define Base3 10000103LL
#define MOD1  1000000007LL
#define MOD2  1000000009LL
#define MOD3  1000000021LL
PLL h1[MX];
LL b1[MX],b2[MX];
void Init() {
    b1[0] = b2[0] = 1;
    for (int i=1; i<MX; i++) {
        b1[i] = (b1[i-1] * Base1)%MOD1;
        b2[i] = (b2[i-1] * Base2)%MOD2;
    }
}
void HashValue(char *s, PLL *h) {
    h[0]= {0,0};
    for (int i=0; i<l1; i++) {
        int x = s[i]-'a'+1;
        h[i+1].F = (h[i].F * Base1 + x)%MOD1;
        h[i+1].S = (h[i].S * Base2 + x)%MOD2;
    }

}
PLL SubStr(PLL *h,int x,int y) {
    PLL ans(0,0);
    if (x <= y) {
        int len = y-x+1;
        ans.X = (h[y].F - (h[x-1].F*b1[len])%MOD1)%MOD1;
        ans.Y = (h[y].S - (h[x-1].S*b2[len])%MOD2)%MOD2;
        ans.X += MOD1;
        ans.X %= MOD1;
        ans.Y += MOD2;
        ans.Y %= MOD2;
    }
    return ans;
}
