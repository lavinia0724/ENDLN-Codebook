/* dfs
只要我有一個小孩不是防火牆，我就必須是防火牆 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000+5;
int cnt = 0;
vector<int> G[maxn];
bool exi[maxn], visited[maxn];
void dfs(int node, int parent){
    if(G[node].size() == 1 && G[node][0] == parent) return;
    for(int i = 0; i < G[node].size(); ++i){
        int now = G[node][i];
        if(visited[now]) continue;
        visited[now] = true;
        dfs(G[node][i], node);
    }
    bool flag = false;
    for(int j = 0; j < G[node].size(); ++j){
        if(exi[G[node][j]] != true && G[node][j] != parent){
            flag = true;
            break;
        }
    }
    if(flag && exi[node] != true){
        exi[node] = true;
        cnt++;
    }
    return;
}
int main(){
    int n;
    while(cin >> n && n){
        for(int i = 1; i <= n; ++i) G[i].clear();
        memset(exi, false, sizeof(exi));
        memset(visited, false, sizeof(visited));
        for(int i = 1; i <= n; ++i){
            int siz;
            cin >> siz;
            for(int j = 0; j < siz; ++j){
                int num;
                cin >> num;
                G[i].emplace_back(num);
            }
        }
        cnt = 0;
        dfs(1, 1);
        if(n == 1) cnt++;
        cout << cnt << endl;
    }
}