int BIT[MX];
void update(int x,int value) {
    while(x<MX) {
        BIT[x] += value;
        x += (x &(-x));
    }
}
int query(int x) {
    int ret = 0;
    while(x) {
        ret += BIT[x];
        x -= (x &(-x));
    }
    return ret;
}

