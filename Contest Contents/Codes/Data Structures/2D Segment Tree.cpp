/*
 Calculating minimun for a matrix
 See: https://cp-algorithms.com/data_structures/segment_tree.html
*/
int t[MX][MX];
void buildY(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx) t[vx][vy] = a[lx][ly];
        else t[vx][vy] = min(t[vx*2][vy], t[vx*2+1][vy]);
    } else {
        int my = (ly + ry) / 2;
        buildY(vx, lx, rx, vy*2, ly, my);
        buildY(vx, lx, rx, vy*2+1, my+1, ry);
        t[vx][vy] = min(t[vx][vy*2] , t[vx][vy*2+1]);
    }
}
void buildX(int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        buildX(vx*2, lx, mx);
        buildX(vx*2+1, mx+1, rx);
    }
    buildY(vx, lx, rx, 1, 0, m-1);
}
int queryY(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry) return INF;
    if (ly == tly && try_ == ry) return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return min(queryY(vx, vy*2, tly, tmy, ly, min(ry, tmy)), queryY(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry));
}

int queryX(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx) return INF;
    if (lx == tlx && trx == rx) return queryY(vx, 1, 0, m-1, ly, ry);
    int tmx = (tlx + trx) / 2;
    return min(queryX(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry), queryX(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry));
}
