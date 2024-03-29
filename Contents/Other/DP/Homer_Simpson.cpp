/* dp 背包 - 時間/數量 - 漢堡
3 5 54
吃 3 分鐘漢堡時
0 -1 -1 1 -1 -1 2 -1 -1 3 -1 -1 4 -1 -1 5 -1 -1 6 -1 -1 7 -1 -1 8 -1 -1 9 -1 -1 10 -1 -1 11 -1 -1 12 -1 -1 13 -1 -1 14 -1 -1 15 -1 -1 16 -1 -1 17 -1 -1 18
吃 5 分鐘漢堡時 (更新)
0 -1 -1 1 -1 1 2 -1 2 3 2 3 4 3 4 5 4 5 6 5 6 7 6 7 8 7 8 9 8 9 10 9 10 11 10 11 12 11 12 13 12 13 14 13 14 15 14 15 16 15 16 17 16 17 18
只有當該時間可剛好吃滿漢堡時會更新
全部初始設 -1，用以判斷 譬如當 1 分鐘時 吃不了任何漢堡*/
int main(){
    int m, n, t;
    while(cin >> m >> n >> t){
        int dp[10000+5];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for(int i = m; i <= t; i++)
            if(dp[i - m] != -1)
                dp[i] = max(dp[i], dp[i - m] + 1);
        for(int i = n; i <= t; i++)
            if(dp[i - n] != -1)
                dp[i] = max(dp[i], dp[i - n] + 1);
        // 時間無法剛好吃滿的時候
        if(dp[t] == -1){
            for(int i = t; i >= 0; i--)
                if(dp[i] != -1){
                    cout << dp[i] << " " << t - i << endl;
                    break;
                }
        }
        else cout << dp[t] << endl;
    }
}