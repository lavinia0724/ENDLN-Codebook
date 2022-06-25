/* dp 背包 - 重量/價值/可重複使用
因為這題可以重複使用同一條魔法
所以可以這樣dp*/
int h, n;
cin >> h >> n;
for(int i = 1; i <= n; i++){
    cin >> a[i] >> b[i];
}
memset(dp, 0x3f3f3f3f, sizeof(dp));
dp[0][0] = 0;
for(int i = 1; i <= n; i++){
    for(int j = 0; j <= h; j++){
        dp[i][j] = min(dp[i-1][j], dp[i][max(0, j - a[i])] + b[i]);
    }
}
cout << dp[n][h] << endl;