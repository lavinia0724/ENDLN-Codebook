/* dp 背包 - 時間/數量/價值 - 第幾分鐘符合
w[i]: 3
陣列每一格代表的意義是最大上限為 index 時可以放入的最大 value
0 0 0 30 30 30 30 30 30
w[i]: 4
0 0 0 30 50 50 50 80 80
w[i]: 5
0 0 0 30 50 60 60 80 90  */
int main(){
    int N, W;
    cin >> N >> W;
    int w[100000+5], v[100000+5];
    for(int i = 0; i < N; i++)
        cin >> w[i] >> v[i];
    long long int dp[100000+5];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < N; i++)
        for(int j = W; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    cout << dp[W] << endl;
}