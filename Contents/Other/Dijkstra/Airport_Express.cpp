/* Dijkstar 捷徑票 */
int n, m, S, T;
const int inf = 1e9;
const int maxn = 20000 + 5;
struct Edge{
    int v, w;
};
struct Item{
    int u, dis;
    // 取路徑最短
    bool operator < (const Item &other) const{
        return dis > other.dis;
    }
};
int dis[maxn], from[maxn];
vector<Edge> G[maxn];
void dijkstra(int s){
    for(int i = 0; i <= n; i++)
        dis[i] = inf;
    dis[s] = 0;
    for(int i = 0; i <= n; i++)
        from[i] = i;
    priority_queue<Item> pq;
    pq.push({s, 0});
    while(!pq.empty()){
        // 取路徑最短的點
        Item now = pq.top();
        pq.pop();
        if(now.dis > dis[now.u])
            continue;
        // 鬆弛 更新
        // 把與 now.u 相連的點都跑一遍
        for(Edge e : G[now.u]){
            if(dis[e.v] > now.dis + e.w){
                dis[e.v] = now.dis + e.w;
                from[e.v] = now.u;
                pq.push({e.v, dis[e.v]});
            }
        }
    }
}
deque<int> ans;
void dfs(int T){
    ans.emplace_back(T);
    if(from[T] != T) dfs(from[T]);
}
int main(){
    bool space = false;
    while(cin >> n >> S >> T){
        if(!space) space = true;
        else cout << endl;
        for(int i = 0; i <= n; i++)
            G[i].clear();
        ans.clear();
        cin >> m;
        int u, v, w;
        for(int i = 0; i < m; i++){
            cin >> u >> v >> w;
            // 無向圖
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        dijkstra(S);
        dfs(T);
        int ori = dis[T];
        int mini = dis[T], state = 0;
        int ticket;
        cin >> ticket;
        for(int i = 0; i < ticket; ++i){
            cin >> u >> v >> w;
            G[u].push_back({v, w});
            dijkstra(S);
            if(dis[T] < mini){
                mini = min(mini, dis[T]);
                state = u;
                ans.clear();
                dfs(T);
            }
            G[u].pop_back();
            G[v].push_back({u, w});
            dijkstra(S);
            if(dis[T] < mini){
                mini = min(mini, dis[T]);
                state = v;
                ans.clear();
                dfs(T);
            }
            G[v].pop_back();
        }
        for(int i = ans.size()-1; i > 0; i--)
            cout << ans[i] << " ";
        cout << ans[0];
        cout << endl;
        if(mini == ori)
            cout << "Ticket Not Used" << endl;
        else
            cout << state << endl;
        cout << mini << endl;
    }
}