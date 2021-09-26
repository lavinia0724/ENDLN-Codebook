// init：dp[i][0] = dp[0][i] = 0
// tren：dp[i][j] =
    // if a[i] = b[j]
        // dp[i − 1][j − 1] + 1
    // else
        // max(dp[i − 1][j], dp[i][j − 1])
// LIS
    // init：dp[0] = 0
    // tren：dp[i] = max{dp[j] | ∀j < i and A[j] < A[i]} + 1
// LIS → LCS (嚴格遞增)
    // A 為原序列，B = sort(A)
    // 對 A, B 做 LCS
// LCS → LIS (數字重複、有數字在 B 裡面不在 A 裡面)
    // A, B 為原本的兩序列
    // 對 A 序列作編號轉換，將轉換規則套用在 B
    // 對 B 做 LIS
int dp[a.size() + 1][b.size() + 1];
for(int i = 0; i <= a.size(); i++){
    dp[i][0]= 0;
}
for(int i = 0; i <= b.size(); i++){
    dp[0][i] = 0;
}

for(int i = 1; i <= a.size(); i++){
    for(int j = 1; j <= b.size(); j++){
        if(a[i - 1] == b[j - 1]){
            dp[i][j] = dp[i - 1][j - 1] + 1;
        }
        else{
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}

return 0;