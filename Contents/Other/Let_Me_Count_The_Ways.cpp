// dp - 時間/數量 - 硬幣排序
long long int n, dp[30000+5];
int coin[] = {1, 5, 10, 25, 50};
memset(dp, 0, sizeof(dp));
dp[0] = 1;
for(int i = 0; i < 5; i++){
    for(int j = coin[i]; j < 30000+5; j++){
        if(dp[j - coin[i]] != -1){
            dp[j] += dp[j - coin[i]];
        }
    }
}
while(cin >> n){
    if(dp[n] == 1){
        cout << "There is only " << dp[n] << " way to produce " << n << " cents change." << endl;
    }
    else{
        cout << "There are " << dp[n] << " ways to produce " << n << " cents change." << endl;
    }
}