// dp 背包 - 重量/是否成立
int t;
cin >> t;
cin.ignore();
while(t--){
    string str;
    getline(cin , str);
    vector<int> v;
    stringstream ss;
    int num, cnt = 0, sum = 0;;
    bool dp[4000+5];
    memset(dp, false, sizeof(dp));
    ss << str;
    while(ss >> num){
        cnt++;
        sum += num;
        v.emplace_back(num);
    }
    if(sum & 1){
        cout << "NO" << endl;
        continue;
    }
    dp[0] = true;
    for(int i = 0; i < v.size(); i++){
        for(int j = sum; j >= v[i]; j--){
            if(dp[j - v[i]]){
                dp[j] = true;
            }
        }
    }
    cout << (dp[sum/2] ? "YES" : "NO") << endl;
}