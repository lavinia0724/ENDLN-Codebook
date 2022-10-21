struct Edge{
    int u, v;
    double w;
    bool operator < (const Edge &rhs) const{
        return w < rhs.w;
    }
}edge[maxn * maxn];
vector<Edge> G[maxn]; // 紀錄有哪些邊在 MST 上
int parent[maxn];
// disjoint set
int find(int x){
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}
bool unite(int a, int b){
    int x = find(a);
    int y = find(b);
    if(x == y) return false;
    parent[x] = y;
    return true;
}
double kruskal(){
    m = 0; // m: 邊的數量
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            edge[m++] = (Edge){i, j, dist(i, j)};
    sort(edge, edge + m);
    for(int i = 0; i < n; ++i){
        parent[i] = i;
        G[i].clear();
    }
    double total = 0.0;
    int edge_cnt = 0;
    for(int i = 0; i < m; ++i){
        int u = edge[i].u, v = edge[i].v;
        double cnt = edge[i].w;
        if(unite(u, v)){
            G[u].push_back((Edge){u, v, cnt});
            G[v].push_back((Edge){v, u, cnt});
            total += cnt;
            if(++edge_cnt == n-1) break;
        }
    }
    return total;
}