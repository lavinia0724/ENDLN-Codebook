/* dp - 數量
col = 蘋果 n
row = 盤子 m
* 0 1 2 3 4
1 1 1 1 1 1
2 1 1 2 2 3
3 1 1 2 3 4 */
int dp[10+5];
int main(){
	int t; cin >> t;
	while(t--){
		int n, m;
		cin >> m >> n;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(int i = 1; i <= n; ++i)
			for(int j = i; j <= m; ++j)
				dp[j] += dp[j - i];
		cout << dp[m] << endl;	
	}
}