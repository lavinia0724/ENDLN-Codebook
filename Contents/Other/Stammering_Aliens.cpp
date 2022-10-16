/* hash 字串 + 二分搜尋 */
#define ull unsigned long long int
const int maxn = 40000+5;
const ull seed = 131;
ull pw[maxn], hhash[maxn], hhash2[maxn];
int m, len;
char str[maxn];
map<ull, int> mp;
void init(){
    hhash[0] = 0;
    for(int i = len-1; i >= 0; --i){
        hhash[i] = (hhash[i+1] * seed + str[i]);
    }
}
int check(int x){
    for(int i = 0; i + x - 1 < len; ++i){
        ull tmp = hhash[i] - (hhash[i + x] * pw[x]);
        hhash2[i] = tmp;
    }
    sort(hhash2, hhash2 + len - x + 1);
    int cnt = 0;
    for(int i = 0; i < len - x + 1; ++i){
        if(i && hhash2[i] == hhash2[i-1])
            cnt++;
        else{
            if(cnt >= m) return 1;
            cnt = 1;
        }
    }
    if(cnt >= m) return 1;
    return 0;
}
int main(){
    pw[0] = 1;
    for(int i = 1; i < maxn; ++i)
        pw[i] = (pw[i-1] * seed);
    while(scanf("%d", &m) && m){
        scanf("%s", str);
        len = strlen(str);
        init();
        int lef = 1, rig = len + 1;
        while(lef < rig){
            int mid = (lef + rig) >> 1;
            if(check(mid))
                lef = mid + 1;
            else rig = mid; 
        }
        int ans = rig - 1;
        if(!ans){
            puts("none");
            continue;
        }
        int pos;
        mp.clear();
        for(int i = 0; i + ans - 1 < len; ++i){
            ull tmp = hhash[i] - hhash[i + ans] * pw[ans];
            mp[tmp]++;
            if(mp[tmp] >= m) pos = i;
        }
        printf("%d %d\n", ans, pos);
    }
    return 0;
}