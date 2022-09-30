/* 二分圖最大匹配
匈牙利演算法 Hungarian algorithm*/
const int maxn = 500+5;
int bn, gn;
int match[maxn];
bool visited[maxn];
vector<vector<int>> G(maxn);
struct People{
    int h;
    string music, sport;
    // constructor
    People(){}
    People(int h, string music, string sport){
        this->h = h;
        this->music = music;
        this->sport = sport;
    }
}lef[maxn], rig[maxn];
bool check(People boy, People girl){
    if(abs(boy.h - girl.h) <= 40 && boy.music == girl.music && boy.sport != girl.sport) return true;
    return false;
}
bool dfs(int s){
    for(int i = 0; i < G[s].size(); ++i){
        int v = G[s][i];
        if(visited[v]) continue;
        visited[v] = true;
        // 如果這個女生還沒被配對過，直接匹配
        // 如果已經被配對，則根據這個女生所配對的對象 dfs 重新匹配所有人的對象
        if(match[v] == -1 || dfs(match[v])){
            match[v] = s;
            return true;
        }
    }
    return false;
}
int Hungarian(){
    int cnt = 0;
    memset(match, -1, sizeof(match));
    for(int i = 0; i < bn; ++i){
        memset(visited, false, sizeof(visited));
        if(dfs(i)) cnt++;
    }
    return cnt;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        bn = 0, gn = 0;
        for(int i = 0; i <= N; ++i) G[i].clear();
        int h;
        string sex, music, sport;
        for(int i = 0; i < N; ++i){
            cin >> h >> sex >> music >> sport;
            if(sex == "M")
                lef[bn++] = People(h, music, sport);
            else
                rig[gn++] = People(h, music, sport);
        }
        for(int i = 0; i < bn; ++i)
            for(int j = 0; j < gn; ++j)
                if(check(lef[i], rig[j]))
                    G[i].emplace_back(j);
        cout << N - Hungarian() << endl;
    }
}