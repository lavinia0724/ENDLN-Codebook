/* dp - 路徑/隊伍分配救難所 */
const int maxn = 4000+5;
int path[maxn][maxn];
long long int dp[maxn][maxn];
struct Edge{
    int idx, position;
    bool operator < (const Edge &rhs) const{
        return position < rhs.position;
    }
}team[maxn], shelter[maxn];
int main(){
    int n;
    while(cin >> n){
        for(int i = 1; i <= n; ++i){
            cin >> team[i].position;
            team[i].idx = i;
        }
        sort(team + 1, team + n + 1);
        int m; cin >> m;
        for(int i = 1; i <= m; ++i){
            cin >> shelter[i].position;
            shelter[i].idx = i;
        }
        sort(shelter + 1, shelter + m + 1);
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        dp[1][0] = 0;
        for(int i = 1; i <= m; ++i){
            for(int j = i; j <= n; ++j){
                // dp[i][j] = min(dp[i][j-1], dp[i-1][j-1]) + abs(team[j].position - shelter[i].position);
                if(dp[i][j-1] <= dp[i-1][j-1]){
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j-1]) + abs(team[j].position - shelter[i].position);
                    path[i][j] = 0; // 從左邊來，前面的 teams 有人來 j shelter
                }
                else{
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j-1]) + abs(team[j].position - shelter[i].position);
                    path[i][j] = 1; // 從左上來，前面的 teams 不會來 j shelter
                }
            }
        }
        int now_shelter = m;
        int ans[maxn];
        // 紀錄路徑，若從左邊來，上一隊也來此；若從右邊來，上隊沒人來此
        for(int i = n; i > 0; --i){
            ans[team[i].idx] = shelter[now_shelter].idx;
            now_shelter -= path[now_shelter][i];
        }
        cout << dp[m][n] << endl;
        for(int i = 1; i < n; ++i)
            cout << ans[i] << " ";
        cout << ans[n] << endl;
    }
}