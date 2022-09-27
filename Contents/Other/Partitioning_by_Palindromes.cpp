/*string & dp - 字串長度判斷迴文*/
bool check_palindromes(int lef, int rig){
    // 比較字串兩端都是迴文
    while(lef < rig){
        if(str[lef] != str[rig]) return 0;
        lef++;
        rig--;
    }
    return 1;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> str;
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        dp[0] = 0;
        for(int i = 0; i < str.size(); ++i)
            for(int j = 0; j <= i; ++j)
                if(str[i] == str[j])
                    if(check_palindromes(j, i))
                        if(dp[i+1] > dp[j] + 1)
                            dp[i+1] = dp[j] + 1;
        cout << dp[str.size()] << endl;
    }
}