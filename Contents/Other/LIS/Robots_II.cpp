/* LIS
No.:   2  4 11 13 25 28 41 42
LIS:   1  2  3  4  4  5  5  5
num:   1  1  1  1  1  2  2  4
path: -1  0  1  2  2  3  3  5 */
const int maxn = 100+5;
int r, c;
vector<int> G;
int LIS[maxn * maxn], num[maxn * maxn], path[maxn * maxn];
bool garbage[maxn][maxn];
void show_path(int n){
    if(path[n] != -1) show_path(path[n]);
    if((n != G.size() - 1) || garbage[r][c]) cout << " " << G[n];
}
int main(){
    int ca = 1;
    while(cin >> r >> c && (r != -1) && (c != -1)){
        memset(garbage, false, sizeof(garbage));
        G.clear();
        int x, y;
        while(cin >> x >> y && x && y){
            garbage[x][y] = true;
        }
        // 紀錄有垃圾的點的編號
        for(int i = 1; i <= r; ++i){
            for(int j = 1; j <= c; ++j){
                if(garbage[i][j]) G.emplace_back((i - 1) * c + j);
            }
        }
        // 如果終點沒有垃圾，假設他有
        if(!garbage[r][c]) G.emplace_back(r * c);
        G.emplace_back(0);
        // i 和 j 是按照編號大小順序由小排到大的垃圾編號
        for(int i = 0; i < G.size(); ++i){
            LIS[i] = 1; 
            num[i] = 1; 
            path[i] = -1;
            for(int j = 0; j < i; ++j){
                // 判斷垃圾的 col 前後
                if(((G[j] - 1) % c) <= ((G[i] - 1) % c)){
                    // num 是經過的路徑數量。path 是從誰來
                    if(LIS[i] == LIS[j] + 1){
                        num[i] += num[j];
                    }
                    else if(LIS[i] < LIS[j] + 1){
                        LIS[i] = LIS[j] + 1;
                        num[i] = num[j];
                        path[i] = j;
                    }
                }
            }
        }
        G.pop_back();
        // 要把假設還回去
        if(!garbage[r][c]) LIS[G.size() - 1]--;
        cout << "CASE#" << ca++ << ": " << LIS[G.size() - 1] << " " << num[G.size() - 1];
        show_path(G.size() - 1);
        cout << endl;
    }
}