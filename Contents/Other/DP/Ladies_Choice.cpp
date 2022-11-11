/* dp - ladies & men */
const int maxn = 1000+5;
int n;
int man[maxn][maxn], manidx[maxn], lady[maxn][maxn], ladyidx[maxn];
int dp[maxn];
deque<int> dq;
void dp_func(){
    while(!dq.empty()){
        int man_now = dq.front();
        dq.pop_front();
        // manidx 現在指著的 lady
        int lady1 = manidx[man_now];
        // man 目前最想要的 lady
        int lady_first = man[man_now][lady1];
        // ladyidx 現在指著的 man
        int man1 = ladyidx[lady_first];
        if(man1 == 0){
            dp[man_now] = lady_first;
            ladyidx[lady_first] = man_now;
        }
        else if(lady[lady_first][man1] > lady[lady_first][man_now]){
            dp[man_now] = lady_first;
            manidx[man1]++;
            dq.emplace_back(man1);
            ladyidx[lady_first] = man_now;
        }
        else{
            dq.emplace_back(man_now);
            manidx[man_now]++;
        }
    }
}
int main(){
    int t; cin >> t;
    bool space = false;
    while(t--){
        cin >> n;
        if(space) cout << endl;
        space = true;
        memset(man, 0, sizeof(man));
        memset(lady, 0, sizeof(lady));
        memset(manidx, 0, sizeof(manidx));
        memset(ladyidx, 0, sizeof(ladyidx));
        dq.clear();
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j)
                cin >> man[i][j];
            dq.emplace_back(i);
            manidx[i] = 1;
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                int man_lady;
                cin >> man_lady;
                lady[i][man_lady] = j;
            }
        }
        dp_func();
        for(int i = 1; i <= n; ++i)
            cout << dp[i] << endl;
    }
}