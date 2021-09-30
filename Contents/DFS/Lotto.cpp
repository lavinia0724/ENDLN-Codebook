void dfs( int depth, int now ){

    // 題目要求每 6 個元素做排列組合
    if( depth == 6 ){

        for( int i = 0; i < 6; i++ ){
            if( i ){
                cout << " ";
            }
            cout << ans[i];
        }
        cout << endl;

        // 這個 return 很重要!! 沒有他會 RE 
        return;
    }

    for( int i = now; i < k; i++ ){

        ans[ depth ] = input[ i ];
        dfs( depth + 1, i + 1 );

        // 當 depth = 6 後 會回來做這個 for 迴圈
        // 此時 depth = 5 回到上一次 call dfs 前的深度
        // 此時 i = i ，但因此時 for 迴圈走向下一迴 i++ 於是 i = i + 1
        // 然後將 input[i] 的值 覆蓋過 ans[5] 接著 call dfs 去輸出 再 return 回來
        // 依此類推 當 depth = 5 做完後 會到 depth = 4 ...
    }
}

int main(){

    bool flag = false;
    while( cin >> k && k ){

        if( flag ){
            cout << endl;
        }

        int n;
        for( int i = 0; i < k; i++ ){         
            cin >> n;
            input.push_back(n);
        }

        // 從深度為 0 開始往下
        dfs( 0, 0 );

        flag = true;
        input.clear();
    }
}