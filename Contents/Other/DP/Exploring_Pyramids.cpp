/* dp - 排列組合/迴文
給一段字串，可以排多少種迴文組合 */
const int maxn = 300 + 5;
const int MOD = 1e9;
string str;
long long int dp[maxn][maxn];
int main(){
    // dp(i, j) = sum{d(i + 1, k - 1) * dp(k, j)}
    while(cin >> str){
        memset(dp, 0, sizeof(dp));
        for(int len = 0; len < str.size(); len += 2){
            for(int lef = 0; lef + len < str.size(); ++lef){
                int rig = lef + len;
                if(lef == rig) dp[lef][rig] = 1;
                for(int k = lef + 2; k <= rig; k += 2){
                    if(str[lef] == str[k] && str[k] == str[rig])
                        dp[lef][rig] = (dp[lef][rig] + dp[lef+1][k-1] * dp[k][rig]) % MOD;
                }
            }
        }
        cout << dp[0][str.size() - 1] << endl;
    }
}