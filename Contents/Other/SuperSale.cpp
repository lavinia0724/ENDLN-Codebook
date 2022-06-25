// dp 背包 - 重量/價值/不可重複使用 - 舉重
int t;
cin >> t;
while(t--){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> edge[i].p >> edge[i].w;
    }
    int g, total = 0;
    cin >> g;
    for(int i = 0; i < g; i++){
        int pw, dp[30+5];
        cin >> pw;
        memset(dp, 0, sizeof(dp));
        for(int j = 0; j < n; j++){
            for(int k = pw; k >= edge[j].w; k--){
                dp[k] = max(dp[k], dp[k - edge[j].w] + edge[j].p);
            }
        }
        total += dp[pw];
    }
    cout << total << endl;
}