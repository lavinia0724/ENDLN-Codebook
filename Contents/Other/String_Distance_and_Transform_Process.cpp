/* MED - Minimum Edit Distance
增加刪除修改 使得字串A 以最小步驟數替換成 字串B
abcac
bcd
  j 0 b c d
i +--------
0 | 0 1 2 3
a | 1 1 2 3
b | 2 1 2 3
c | 3 2 1 2
a | 4 3 2 2
c | 5 4 3 3
1 Delete 1
2 Replace 3,d
3 Delete 4 */
const int maxn = 80+5;
string strA, strB;
int dis[maxn][maxn];
int cnt;
// 利用 dfs 輸出替換字串的步驟
void backtracking(int i, int j){
    if(i == 0 || j == 0){
        while(i > 0){
            cout << cnt++ << " Delete " << i << endl;
            i--;
        }
        while(j > 0){
            cout << cnt++ << " Insert " << i + 1 << "," << strB[j-1] << endl;
            j--;
        }
        return;
    }
    if(strA[i-1] == strB[j-1]){
        backtracking(i-1, j-1);
    }
    else{
        if(dis[i][j] == dis[i-1][j-1] + 1){
            cout << cnt++ << " Replace " << i << "," << strB[j-1] << endl;
            backtracking(i-1, j-1);
        }
        else if(dis[i][j] == dis[i-1][j] + 1){
            cout << cnt++ << " Delete " << i << endl;
            backtracking(i-1, j);
        }
        else if(dis[i][j] == dis[i][j-1] + 1){
            cout << cnt++ << " Insert " << i + 1 << "," << strB[j-1] << endl;
            backtracking(i, j-1);
        }
    }
}
void MED(){
    // 由於 B 是 0 ，所以 A 轉換成 B 時每個字元都要被刪除
    for(int i = 0; i <= strA.size(); ++i) dis[i][0] = i;
    // 由於 A 是 0 ，所以 A 轉換成 B 時每個字元都需要插入
    for(int j = 0; j <= strB.size(); ++j) dis[0][j] = j;
    for(int i = 1; i <= strA.size(); ++i){
        for(int j = 1; j <= strB.size(); ++j){
            // 字元相同代表不需修改，修改距離直接延續
            if(strA[i-1] == strB[j-1]) dis[i][j] = dis[i-1][j-1];
            else{
                // 取 replace , delete , insert 最小，選其 +1 為最少編輯距離
                dis[i][j] = min(dis[i-1][j-1], min(dis[i-1][j], dis[i][j-1])) + 1;
            }
        }
    }
}
int main(){
    bool space = false;
    while(getline(cin, strA) && getline(cin, strB)){
        cnt = 1;
        MED();
        if(space) cout << endl;
        space = true;
        cout << dis[strA.size()][strB.size()] << endl;
        backtracking(strA.size(), strB.size());
    }
}