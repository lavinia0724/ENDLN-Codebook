/* Segement Tree & RMQ (Range Sum Query)
idx:  1   2   3   4   5   6   7   8   9  10
num: -1  -1   1   1   1   1   3  10  10  10
fre:  2   2   4   4   4   4   1   3   3   3
border
left: 1   1   3   3   3   3   7   8   8   8
right:2   2   6   6   6   6   7  10  10  10 */
# define Lson(x) x << 1
# define Rson(x) (x << 1) + 1
const int maxn = 1e5+5;
struct Tree{
    int lef, rig, value;
}tree[4 * maxn];
struct Num{
    int lef, rig, value, fre;
}num[maxn];
// 建立 segement tree
void build(int lef, int rig, int x){
    tree[x].lef = lef;
    tree[x].rig = rig;
    // 區塊有多長，題目詢問的重點
    if(lef == rig){
        tree[x].value = num[lef].fre;
        return;
    }
    int mid = (lef + rig) >> 1;
    build(lef, mid, Lson(x));
    build(mid + 1, rig, Rson(x));
    tree[x].value = max(tree[Lson(x)].value, tree[Rson(x)].value);
}
// 查詢 segement tree
int query(int lef, int rig, int x){
    // 題目所查詢的區間剛好在同個區塊上，num[lef].v == num[rig].v
    if(num[lef].value == num[rig].value) return rig - lef + 1;
    int ans = 0;
    // 查詢的左區間邊界切到區塊，且此區間有數個區塊
    if(lef > num[lef].lef){ 
        // 計算切到的區間大小
        ans = num[lef].rig - lef + 1; 
        // 更新左邊界至被切區塊的右邊界加一，就不會切到區塊
        lef = num[lef].rig + 1;
    }
    // 查詢的右區間邊界切到區塊，且此區間有數個區塊
    if(rig < num[rig].rig){ 
        // 計算切到的區間大小，並找出最大
        ans = max(ans, rig - num[rig].lef + 1); 
        // 更新右邊界
        rig = num[rig].lef - 1;
    }
    // 如果左邊界大於右邊界，表示不需要再進行查詢直接回傳答案
    if(lef > rig) return ans; 
    if(tree[x].lef >= lef && tree[x].rig <= rig) return tree[x].value;
    int mid = (tree[x].lef + tree[x].rig) >> 1;
    if(lef <= mid) ans = max(ans, query(lef, rig, Lson(x)));
    if(mid < rig) ans = max(ans, query(lef, rig, Rson(x)));
    return ans;
}
int main(){
    int n, q;
    while(cin >> n && n){
        cin >> q;
        int start = 1;
        for(int i = 1; i <= n; ++i){
            cin >> num[i].value;
            if(num[i].value != num[i-1].value){
                for(int j = start; j < i; ++j){
                    num[j].rig = i - 1;
                    num[j].fre = i - start;
                }
                start = num[i].lef = i;
            }
            else num[i].lef = start;
        }
        // 最後一段 [start, n]
        for(int j = start; j <= n; ++j){
            num[j].rig = n;
            num[j].fre = n - start + 1;
        }
        build(1, n, 1);
        int lef, rig;
        for(int i = 0; i < q; ++i){
            cin >> lef >> rig;
            cout << query(lef, rig, 1) << endl;
        }
    }
}