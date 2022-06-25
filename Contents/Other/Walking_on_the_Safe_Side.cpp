// dp - 地圖更新
int t;
bool space = false;
cin >> t;
while(t--){
    if(space){
        cout << endl;
    }
    else{
        space = true;
    }
    int r, c;
    cin >> r >> c;
    cin.ignore();
    memset(mp, false, sizeof(mp));
    memset(dp, 0, sizeof(dp));
    string str;
    for(int i = 0; i < r; i++){
        getline(cin, str);
        int n, num;
        stringstream ss(str);
        ss >> n;
        while(ss >> num){
            mp[n][num] = true;
        }
    }
    dp[1][1] = 1;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(mp[i][j]){
                continue;
            }
            if(i > 1){
                dp[i][j] += dp[i-1][j];
            }
            if(j > 1){
                dp[i][j] += dp[i][j-1];
            }
        }
    }
    cout << dp[r][c] << endl;
}