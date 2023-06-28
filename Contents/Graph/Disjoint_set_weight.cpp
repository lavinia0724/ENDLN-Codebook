/* 帶權並查集 + 數論 */
const int maxn = 20000+5;
int n, Q, parent[maxn], value[maxn];
int find(int x){
    if(parent[x] != x){
        int tmp = parent[x];
        parent[x] = find(parent[x]);
        value[x] ^= value[tmp];
    }
    return parent[x];
}
bool unionSet(int x, int y, int v){
    int xParent = find(x);
    int yParent = find(y);
    if(xParent == yParent) return (value[x] ^ value[y]) == v;
    if(xParent == n) swap(xParent, yParent);
    parent[xParent] = yParent;
    value[xParent] = value[x] ^ v ^ value[y];
    return true;
}
int main(){
    int p, q, v, k, x, Case = 1;
    while(scanf("%d %d", &n, &Q) && n && Q){
        printf("Case %d:\n", Case++);
        for(int i = 0; i <= n; ++i) parent[i] = i;
        memset(value, 0, sizeof(value));
        char str[100+5];
        bool flag = false;
        int facts = 0;
        for(int i = 0; i < Q; ++i){
            scanf("%s", str);
            if(str[0] == 'I'){
                gets(str);
                facts++;
                if(flag) continue;
                int cnt = sscanf(str, "%d %d %d", &p, &q, &v);
                if(cnt == 2){
                    v = q;
                    q = n;
                }
                if(!unionSet(p, q, v)){
                    flag = true;
                    printf("The first %d facts are conflicting.\n", facts++);
                }
            }
            else{
                scanf("%d", &k);
                int ans = 0;
                bool check = true;
                map<int, int> mp;
                for(int j = 0; j < k; ++j){
                    scanf("%d", &x);
                    if(flag) continue;
                    int xParent = find(x);
                    ans ^= value[x];
                    mp[xParent]++;
                }
                if(flag) continue;
                map<int, int>::iterator it;
                for(it = mp.begin(); it != mp.end(); it++){
                    if(it->second % 2){
                        if(it->first != n){
                            check = false;
                            break;
                        }
                        else ans ^= value[it->first];
                    }
                }
                if(check) printf("%d\n", ans);
                else printf("I don't know.\n");
            }
        }
        printf("\n");
    }
}
