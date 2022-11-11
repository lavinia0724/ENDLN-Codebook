/* 特定排序後放入格子
以右邊大小排序 要從左邊開始放
以左邊大小排序 要從右邊開始放 */
int n;
const int maxn = 5000+5;
struct Edge{
    int lef, rig, pos, idx;
    bool operator < (const Edge &rhs) const{
        if(rig != rhs.rig)
            return rig < rhs.rig;
        else
            return lef < rhs.lef; 
    }
}x[maxn], y[maxn];
bool used[maxn];
bool solve_x(){
    memset(used, false, sizeof(used));
    for(int i = 0; i < n; ++i){
        x[i].pos = 0; 
        for(int j = x[i].lef; j <= x[i].rig; ++j){
            if(!used[j]){
                x[i].pos = j;
                used[j] = true;
                break;
            }
        }
        if(x[i].pos == 0) return false;
    }
    return true;
}
bool solve_y(){
    memset(used, false, sizeof(used));
    for(int i = 0; i < n; ++i){
        y[i].pos = 0;
        for(int j = y[i].lef; j <= y[i].rig; ++j){
            if(!used[j]){
                y[i].pos = j;
                used[j] = true;
                break;
            }
        }
        if(y[i].pos == 0) return false;
    }
    return true;
}
int main(){
    while(cin >> n && n){
        int x1, y1, x2, y2;
        for(int i = 0; i < n; ++i){
            cin >> x1 >> y1 >> x2 >> y2;
            x[i].lef = min(x1, x2);
            x[i].rig = max(x1, x2);
            y[i].lef = min(y1, y2);
            y[i].rig = max(y2, y2);
            x[i].idx = y[i].idx = i;
            x[i].pos = y[i].pos = 0;
        }   
        sort(x, x + n);
        sort(y, y + n);
        if(!solve_x() || !solve_y()) cout << "IMPOSSIBLE" << endl;
        else{
            int ans_x[maxn], ans_y[maxn];
            for(int i = 0; i < n; ++i){
                ans_x[x[i].idx] = x[i].pos;
                ans_y[y[i].idx] = y[i].pos; 
            }
            for(int i = 0; i < n; ++i)
                cout << ans_x[i] << " " << ans_y[i] << endl;
        }
    }
}