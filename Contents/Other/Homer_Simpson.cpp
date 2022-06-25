// dp 背包 - 時間/數量 - 漢堡
int m, n, t;
while(cin >> m >> n >> t){
    int dp[10000+5];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i = m; i <= t; i++){
        if(dp[i - m] != -1){
            dp[i] = max(dp[i], dp[i - m] + 1);
        }
    }
    for(int i = n; i <= t; i++){
        if(dp[i - n] != -1){
            dp[i] = max(dp[i], dp[i - n] + 1);
        }
    }
    if(dp[t] == -1){ // 時間無法剛好吃滿的時候
        for(int i = t; i >= 0; i--){
            if(dp[i] != -1){
                cout << dp[i] << " " << t - i << endl;
                break;
            }
        }
    }
    else{
        cout << dp[t] << endl;
    }
}