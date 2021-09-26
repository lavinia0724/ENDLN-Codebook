// f(1, j) = f(i, 1) = 1
// f(i, j) = f(i - 1, j) + f(i, j - 1)
int dp[105][105];
dp[1][1] = 1;
for(int i = 1; i <= 100: ++i){
    for(int j = 1; j <= 100; ++j){
        if(i + 1 <= 100) dp[i + 1][j] += dp[i][j];
        if(j + 1 <= 100) dp[i][j + 1] += dp[i][j];
    }
}