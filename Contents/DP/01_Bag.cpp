// 不放：重量和價值不變
    // to f(i, j) = f(i - 1, j)
// 放：重量 + w_i，價值 + v_i 
    // to f(i, j) = f(i - 1, j - w_i) + v_i
// tren：f(i, j) = max(f(i - 1, j), f(i - 1, j - w_i) + v_i)
int dp[MXN + 1][MXW + 1];
memset(dp, 0, sizeof(dp));
for (int i = 1; i <= MXN; ++i){
    for (int j = 0; j < w[i]; ++j){
        dp[i][j] = dp[i - 1][j];
    }
    for (int j = w[i]; j <= MXW; ++j){
        dp[i][j] = max(dp[i - 1][j − w[i]] + v[i], dp[i - 1][j]);
    }
}
cout << dp[MXN][MXW] << '\n';