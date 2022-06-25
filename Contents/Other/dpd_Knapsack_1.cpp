// dp 背包 - 時間/數量/價值 - 第幾分鐘符合
int N, W;
cin >> N >> W;
int w[100000+5];
int v[100000+5];
for(int i = 0; i < N; i++){
    cin >> w[i] >> v[i];
}
long long int dp[100000+5];
memset(dp, 0, sizeof(dp));
for(int i = 0; i < N; i++){
    for(int j = W; j >= w[i]; j--){
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
}
cout << dp[W] << endl;