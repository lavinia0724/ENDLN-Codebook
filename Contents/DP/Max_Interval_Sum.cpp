// No Limit
int ans = A[1];
sum[1] = dp[1] = A[1];

for(int i = 2; i <= n; ++i){
    sum[i] = A[i] + sum[i - 1];
    dp[i] = min(dp[i - 1], sum[i]);
    ans = max(ans, sum[i] - dp[i - 1]);
}

// length <= L
int a[15] = {0, 6, -8, 4, -10, 7, 9, -6, 4, 5, -1};
int sum[15];

int main(){
    int L = 3, ans = 0;
    for (int i = 1; i <= 10; ++i)
    {
        sum[i] = a[i] + sum[i - 1];
    }
    deque<int> dq;
    dq.push_back(0);
    for (int i = 1; i <= 10; ++i){
        if (i - dq.front() > L){
            dq.pop_front();
        }
        ans = max(ans, sum[i] - sum[dq.front()]);
        while(!dq.empty() && sum[i] < sum[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << ans << '\n';
}