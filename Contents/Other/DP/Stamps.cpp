/* dp - dfs/分配可能性並更新 */
const int maxn = 100+5;
int h, k, r, maxi = 0;
int x[maxn], y[maxn];
int ans[maxn]; // 存可貼出最大郵票值的面額
void dfs(int i){
    // 若 x[i] 的 i 多於可貼的郵票數量
    if(i >= k){
        if(r > maxi){
            maxi = max(maxi, r);
            for(int i = 0; i < k; ++i)
                ans[i] = x[i];
        }
        return;
    }
    // 存此層尚未更新前的 r、y 值，因為 dfs 完要回去上一層
    int r_before_this_layer = r;
    int y_before_this_layer[maxn]; 
    for(int j = 0; j < maxn; ++j)
        y_before_this_layer[j] = y[j];
    // next: 下一可考慮的郵票面額
    // postage: 貼完郵票的總面額(y的idx)
    // num: 要貼幾張
    // x[i-1] 要 -1 是因為 x 從 0 開始存第一種面額
    for(int next = x[i-1] + 1; next <= r + 1; ++next){
        x[i] = next;
        for(int postage = 0; postage < x[i-1] * h; ++postage){
            if(y[postage] >= h) continue;
            for(int num = 1; num <= h - y[postage]; ++num)
                if(y[postage] + num < y[postage + num * next] && (postage + num * next < maxn))
                    y[postage + num * next] = y[postage] + num;
        }
        // 更新現在連續最大值到多少
        while(y[r+1] < 0x3f3f3f) r++;
        // x 可貼面額種類多 1
        dfs(i+1);
        // 還原 r、y 值
        r = r_before_this_layer;
        for(int j = 0; j < maxn; ++j)
            y[j] = y_before_this_layer[j];
    }
}
int main(){
    while(cin >> h >> k && h && k){
        memset(x, 0, sizeof(x));
        memset(y, 0x3f3f3f3f, sizeof(y));
        x[0] = 1;
        r = h;
        // x[0] = 1，1 張郵票可貼到的最大值
        for(int i = 0; i <= r; ++i)
            y[i] = i;
        maxi = 0;
        dfs(1);
        for(int i = 0; i < k; ++i)
            printf("%3d", ans[i]);
        printf(" ->%3d\n", maxi);
    }
}