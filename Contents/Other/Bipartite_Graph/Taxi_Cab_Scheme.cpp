/* 二分圖最大匹配
匈牙利演算法 Hungarian algorithm */
const int maxn = 500+5;
int n;
int match[maxn];
bool visited[maxn];
vector<int> G[maxn];
struct People{
    int s, x1, y1, x2, y2;
    bool operator < (const People & rhs) const {
        return s < rhs.s;
    }
}p[maxn];
bool check(People boy, People girl){
    int tmp = boy.s + abs(boy.x2 - boy.x1) + abs(boy.y2 - boy.y1) + abs(boy.x2 - girl.x1) + abs(boy.y2 - girl.y1);
    if(tmp < girl.s) return true;
    return false;
}
bool dfs(int s){
    for(int i = 0; i < G[s].size(); ++i){
        int v = G[s][i];
        if(visited[v]) continue;
        visited[v] = true;
        if(match[v] == -1 || dfs(match[v])){
            match[v] = s;
            return true;
        }
    }
    return false;
}
int Hungarian(){
    int cnt = 0;
    meset(match, -1, sizeof(match));
    for(int i = 0; i < n; ++i){
        memset(visited, false, sizeof(visited));
        if(dfs(i)) cnt++;
    }
    return cnt;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) G[i].clear();
        for(int i = 0; i < n; ++i){
            int h, m;
            scanf("%d:%d", &h, &m);
            p[i].s = h * 60 + m;
            scanf("%d%d%d%d", &p[i].x1, &p[i].y1, &p[i].x2, &p[i].y2);
        }
        sort(p, p + n);
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                if(check(p[i], p[j]))
                    G[i].push_back(j);
        printf("%d\n", n - Hungarian());
    } 
}