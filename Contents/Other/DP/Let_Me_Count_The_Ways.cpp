/* dp - 時間/數量 - 硬幣排序
要湊出 17
1 1 1 1 1 2 2 2 2 2 4 4 4 4 4 6 6 */
int main(){
    long long int n;
    long long int dp[30000+5];
    int coin[] = {1, 5, 10, 25, 50};
    memset(dp, 0, sizeof(dp));
    // 直接把 dp 做好
    dp[0] = 1;
    for(int i = 0; i < 5; i++)
        for(int j = coin[i]; j < 30000+5; j++)
            if(dp[j - coin[i]] != -1)
                dp[j] += dp[j - coin[i]];
    while(cin >> n){
        if(dp[n] == 1)
            cout << "There is only " << dp[n] << " way to produce " << n << " cents change." << endl;
        else
            cout << "There are " << dp[n] << " ways to produce " << n << " cents change." << endl;
    }
}