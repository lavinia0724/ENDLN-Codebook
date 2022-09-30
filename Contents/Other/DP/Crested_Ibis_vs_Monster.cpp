/* dp 背包 - 重量/價值/可重複使用
9 3
8 3
4 2
2 1
0 3 3 3 3 3 3 3 3 6
0 2 2 2 2 3 3 3 3 5
0 1 1 2 2 3 3 3 3 4
因為這題可以重複使用同一條魔法
所以可以這樣dp */
int a[10000+5], b[10000+5];
int dp[10000+5][10000+5];
int main(){
    int h, n;
    cin >> h >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= h; j++)
            dp[i][j] = min(dp[i-1][j], dp[i][max(0, j - a[i])] + b[i]);
    cout << dp[n][h] << endl;
}