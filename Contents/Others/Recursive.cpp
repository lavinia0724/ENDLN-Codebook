int gcd( int i, int j ){

    while( ( j %= i ) != 0  && ( i %= j ) != 0 );
    return j + i;

}

int g( int n ){

    // 已使用過此數字 直接從陣列中呼叫
    if( known[n] ){     
        return known[n];
    }

    else{

        // 利用 g( n - 1) 去確認此次輪迴為尚不知道結果的最大數字
        known[n] += g( n - 1 );

        // 計算本次結果 同時將本次結果儲存於陣列中
        for( int i = 1; i < n; i++ ){
            known[n] += gcd( i, n );          
        }
        return known[n];
    }  
}

int main(){
    
    known[2] = 1;
    int n;

    while( cin >> n ){

        if( n == 0 ){
            break;
        }

        cout << g(n) << endl;

        // 題目方法
        // for( int i = 1; i < n; i++ ){
        //     for( int j = i + 1; j <= n; j++ ){
        //         g += gcd( i, j );
        //     }
        // }
    }
}