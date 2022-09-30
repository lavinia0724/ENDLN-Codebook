/*二分圖 Bipatirate*/
const int maxn = 300+5;
int n;
int color[maxn];
vector<vector<int>> v(maxn);
bool dfs(int s){
    for(auto it : v[s]){
        if(color[it] == -1){
            // 如果與點相連又還未填色，填塞成與原點不同的另一色
            color[it] = 3 - color[s];
            // 同樣對此點去判定與此點相連的點的填色
            if(!dfs(it)) return false;
        }
        if(color[s] == color[it]){
            // 如果相鄰兩點同色，回傳 false
            return false;
        }
    }
    return true;
}
void isBipatirate(){
    bool flag = true;
    for(int i = 1; i <= n; ++i){
        if(color[i] == -1){
            // 如果還未填色過，就先填色成 1，並對與此點相連的點都 dfs 判定填色
            color[i] = 1;
            flag &= dfs(i);
        }
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main(){
    while(cin >> n && n){
        for(int i = 1; i <= n; ++i) v[i].clear();
        memset(color, -1, sizeof(color));
        int a, b;
        while(cin >> a >> b && (a || b)){
            v[a].emplace_back(b);
            v[b].emplace_back(a);
        }
        isBipatirate();
    }
}