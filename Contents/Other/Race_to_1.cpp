const int N = 1000000;
bool sieve[N+5];
vector<int> pri;
double dp[N+5];
void Linear_Sieve(){ // 線性篩
    for (int i = 2; i < N; i++){
        if (!sieve[i])
            pri.push_back(i);
        for (int p: pri){
            if (i * p >= N){     
                break;
            }
            sieve[i * p] = true;   
            if (i % p == 0){      
                break;
            }
        }
    }
}
double dfs(int n){
    if(dp[n] != -1) return dp[n];
    dp[n] = 0;
    if(n == 1) return dp[n];
    int total = 0, prime = 0;
    for(int i = 0; i < pri.size() && pri[i] <= n; i++){
        total++;
        if(n % pri[i]) continue;
        prime++;
        dp[n] += dfs(n/pri[i]);
    }
    dp[n] = (dp[n] + total)/prime; // 算期望值
    return dp[n];
}
int main(){
    int t;
    int num;
    int ca = 1;
    for(int i = 0; i <= N; i++){
        dp[i] = -1;
    }
    Linear_Sieve();
    cin >> t;
    while(t--){
        cin >> num;

        cout << "Case " << ca++ << ": " << fixed << setprecision(10) << dfs(num) << endl;
    }
}