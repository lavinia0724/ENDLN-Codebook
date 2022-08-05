while(cin >> l && l){
    cin >> n;
    vector<int> s(n+2);
    s[0] = 0;
    for(int i = 1; i <= n; ++i) cin >> s[i]; 
    s[++n] = l; // 從現在開始 n 的數量變為 n + 1
    int dp[n+5][n+5];
    memset(dp, 0, sizeof(dp));
    for(int r = 2; r <= n; ++r){ // r: 切幾段 b: 起點 c: 中間點 e: 終點
        for(int b = 0; b < n; ++b){
            if(b + r > n) break;
            int e = b + r;
            dp[b][e] = 0x3f3f3f3f;
            for(int c = b + 1; c < e; ++c){
                dp[b][e] = min(dp[b][e], dp[b][c] + dp[c][e] + s[e] - s[b]);
            }
        }
    }
    cout << "The minimum cutting is " << dp[0][n] << "." << endl;
}