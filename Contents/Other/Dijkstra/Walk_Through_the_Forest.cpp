/* Dijkstra + 路徑最優化 DP */
const int inf = 0x3f3f3f3f;
const int maxn = 1000+5;
int n, m;
struct Edge{
    int v, w;
};
struct Item{
    int u, dis;
    bool operator < (const Item &other) const{
        return dis > other.dis;
    }
};
int dis[maxn];
long long int dp[maxn];
vector<Edge> G[maxn];
vector<int> path[maxn];
void dijkstra(int s){
    for(int i = 0; i <= n; ++i){
        dis[i] = inf;
    }
    dis[s] = 0;
    priority_queue<Item> pq;
    pq.push({s, 0});
    while(!pq.empty()){
        Item now = pq.top();
        pq.pop();

        if(now.dis > dis[now.u]){
            continue;
        }

        for(Edge e: G[now.u]){
            if(dis[e.v] > now.dis + e.w){
                dis[e.v] = now.dis + e.w;
                pq.push({e.v, dis[e.v]});
            }
        }
    }
}
long long int dfs(int u){
    // ans 是 pointer，指向 dp[u] 的記憶體位址
    // 對於 ans 的 value 改變會記錄在 dp[u]
    long long int& ans = dp[u];
    if(ans != -1) return ans;
    if(u == 2) return ans = 1;
    ans = 0;
    for(int i = 0; i < path[u].size(); ++i)
        ans += dfs(path[u][i]);
    return ans;
}
int main(){
    while(cin >> n && n){
        cin >> m;
        for(int i = 0; i <= n; ++i) G[i].clear();
        int u, v, w;
        for(int i = 0; i < m; ++i){
            cin >> u >> v >> w;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        dijkstra(2); // dijkstra 紀錄從終點到每個點的距離
        memset(dp, -1, sizeof(dp));
        for(int i = 1; i <= n; ++i){
            path[i].clear();
            for(int j = 0; j < G[i].size(); ++j){
                int v = G[i][j].v;
                // 如果到 v 的距離比到 i 遠，代表從起點經過 i 再到 v
                if(dis[i] > dis[v])
                    path[i].push_back(v);
            }
        }
        cout << dfs(1) << endl;
    }
}