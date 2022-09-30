/* dp - 動態切割取最小
100
3
25 50 75
dp:
0 0 50 125 200
0 0 0 50 125
0 0 0 0 50
0 0 0 0 0
0 0 0 0 0 */
int main(){
    int l;
    while(cin >> l && l){
        int n;
        cin >> n;
        vector<int> s(n+2);
        s[0] = 0;
        for(int i = 1; i <= n; ++i)
            cin >> s[i];
        // 從現在開始 n 的數量變為 n + 1
        s[++n] = l;
        int dp[n+5][n+5];
        memset(dp, 0, sizeof(dp));
        // r: 切幾段 b: 起點 c: 中間點 e: 終點
        for(int r = 2; r <= n; ++r){
            for(int b = 0; b < n; ++b){
                // 如果從 b 開始切 r 刀會超出長度就 break
                if(b + r > n) break;
                // e: 從 b 開始切 r 刀
                int e = b + r;
                dp[b][e] = 0x3f3f3f3f;
                // c: 遍歷所有從 b 開始到 e 結束的中間點
                for(int c = b + 1; c < e; ++c){
                    // dp[b][c] 從 b 到 c 最少 cost + dp[c][e] 從 c 到 e 最少 cost
                    // s[e] - s[b] 兩段之間的 cost
                    dp[b][e] = min(dp[b][e], dp[b][c] + dp[c][e] + s[e] - s[b]);
                }
            }
        }
        cout << "The minimum cutting is " << dp[0][n] << "." << endl;
    }
}