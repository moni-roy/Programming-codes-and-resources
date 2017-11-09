/*
 * https://topcoder.g.hatena.ne.jp/spaghetti_source/20121027/1351298201
 * If spanning tree require sum(a)/sum(b) maximum and
 * cost given of a edge is e(a,b);
 * */
struct Graph {
    int n;
    struct Edge {
        int u, v, a, b;
    };
    vector<Edge> E;
    Graph(int n) : n(n) { }
    void addEdge(int u, int v, int a, int b) {
        E.push_back({u, v, a, b});
    }
    double fcost, gcost;
    ll A=0,B=0;
    double minimumSpanningTree(double t) {
        fcost = gcost = 0;
        A=B=0;
        UnionFind unionFind(n);
        sort(E.begin(), E.end(), [t](Edge e, Edge f) {
            return e.a - t*e.b < f.a - t*f.b;
        });
        for (Edge e : E)
            if (unionFind.connect(e.u, e.v)) {
                fcost += e.a, gcost += e.b;
            }
        return fcost - t * gcost;
    }
    double fractionalMin() {
        for (double t = 0; ; t = fcost / gcost)
            if (fabs( minimumSpanningTree(t) ) < 1e-8) {
                return t;
            }
    }
};
