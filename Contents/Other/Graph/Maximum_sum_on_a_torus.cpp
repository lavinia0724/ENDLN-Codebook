/* Prefix sum in Graph*/
const int maxn = 80;
const int inf = 0x3f3f3f3f;
int arr[maxn*2 + 5][maxn*2 + 5];
int prefix_sum[maxn*2 + 5][maxn*2 + 5];
int ans[maxn*2];
int n;
int maxSub(int start){
    int maxi, dp;
    maxi = dp = ans[start];
    for(int i = start + 1; i < start + n; ++i){
        dp += ans[i];
        maxi = max(maxi, dp);
    }
    return maxi;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        memset(arr, 0, sizeof(arr));
        cin >> n;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j){
                cin >> arr[i][j];
                arr[n+i][j] = arr[i][n+j] = arr[n+i][n+j] = arr[i][j];
            }
        int len = 2*n;
        memset(prefix_sum, 0, sizeof(prefix_sum));
        for(int i = 0; i < len; ++i)
            for(int j = 0; j < len; ++j){
                if(i == 0) prefix_sum[i][j] = arr[i][j];
                else prefix_sum[i][j] = prefix_sum[i-1][j] + arr[i][j];
            }
        int maxi = -inf;
        for(int i = 0; i < len; ++i){
            for(int j = i; j < i + n && j < len; ++j){
                for(int k = 0; k < len; ++k){
                    if(i == 0) ans[k] = prefix_sum[j][k];
                    else ans[k] = prefix_sum[j][k] - prefix_sum[i-1][k];
                }
                for(int k = 0; k < n; ++k){
                    int answer = maxSub(k);
                    maxi = max(maxi, answer);
                }
            }
        }
        cout << maxi << endl; 
    }
}