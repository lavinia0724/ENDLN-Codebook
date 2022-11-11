/* deque 火車
倒退逆推法 能怎樣進來就能怎樣出去 
lis: 1 2 3 4 5
dq:  3 2 4 1 5
1. 如果 lis front = dq front，dq pop
2. 反之 ans.push dq front，每次檢查 ans top 是否 = lis front
*/
int main(){
    int n;
    while(cin >> n && n){
        int train;
        deque<int> dq;
        while(cin >> train && train){
            dq.emplace_back(train);
            deque<int> lis, ans;
            for(int i = 2; i <= n; ++i){
                cin >> train;
                dq.emplace_back(train);
            }
            for(int i = 1; i <= n; ++i)
                lis.emplace_back(i);
            for(int i = 0, j = 0; j < n, i < n; ++i){
                if(lis[i] == dq[j]) ++j;
                else
                    ans.emplace_back(lis[i]);
                while(!ans.empty()){
                    if(dq[j] != ans.back()) break;
                    ans.pop_back();
                    ++j;
                }
            }
            if(!ans.empty())
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
            dq.clear();
        }
        cout << endl;
    }
}