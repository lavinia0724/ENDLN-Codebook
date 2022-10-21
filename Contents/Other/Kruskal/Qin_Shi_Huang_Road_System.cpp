/* kruskal disjoint set dfs */
const int maxn = 1000 + 5;
int n, m;
int x[maxn], y[maxn], p[maxn];
struct Edge{
    int u, v;
    double w;
    bool operator < (const Edge &rhs) const{
        return w < rhs.w;
    }
}edge[maxn * maxn];
vector<Edge> G[maxn];
int parent[maxn];
// 計算兩點之間的距離
double dist(int a, int b){
    double x2 = (x[a] - x[b]) * (x[a] - x[b]);
    double y2 = (y[a] - y[b]) * (y[a] - y[b]);
    return sqrt(x2 + y2);
}
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
double maxcost[maxn][maxn];
bool visited[maxn];
void dfs(int u){
    visited[u] = true;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i].v;
        if(visited[v]) continue;
        double cost = G[u][i].w;
        maxcost[u][v] = maxcost[v][u] = cost;
        // 更新 MST 樹上的點到 v 點的距離
        for(int j = 0; j < n; ++j)
            if(visited[j])
                maxcost[j][v] = maxcost[v][j] = max(maxcost[j][u], cost);
        dfs(v);
    }
}
void solve(){
    double total = kruskal();
    memset(maxcost, 0, sizeof(maxcost));
    memset(visited, false, sizeof(visited));
    dfs(0);
    double ans = -1;
    // 把所有點都遍歷一次
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            ans = max(ans, (p[i] + p[j]) / (total - maxcost[i][j]));
    printf("%.2lf\n", ans);
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d%d%d", &x[i], &y[i], &p[i]);
        solve();
    }
    return 0;
} 