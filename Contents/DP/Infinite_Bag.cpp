// f(i, j) = max(f(i − 1, j), f(i − 1, j − wi) + vi, f(i, j − wi) + vi)
    // coin chage
        // 最少幾枚能湊成 M 元
            // f(i,j)=min(f(i−1,j),f(i−1,j−ci)+1,f(i,j−ci)+1)
        // 多少種能湊成 M 元
            // f(i, j) = f(i − 1, j) + f(i, j − ci)
int dp[MXW];
memset(dp, -INF, sizeof(dp));
dp[0] = 0;
for (int i = 0; i < N; ++i){
    for (int j = w[i]; j <= MXW; ++j){
        dp[j] = max(dp[j − w[i]] + v[i], dp[j]);
    }
}