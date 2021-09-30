// 給一個字串 s 和一個正整數 d，計算 s 有幾種排列可以被 d 整除
void dfs( int depth, string now ){

    memset( used, true, sizeof(used) );

    // 算此種排列組合是否可以被整除
    if( depth == n ){
        
        digit = 0;
        for( int i = n - 1; i >= 0; i-- ){
            digit *= 10;
            digit += ( now[ i ] - '0' );
        }
        if( digit % d == 0 ){
            quantity++;         
        }
        return;
    }

    // 排列組合
    // 記得用 true/false 確定排過與否
    for( int i = 0; i < n; i++ ){

        if( flag[i] && used[ str[i] - '0' ] ){

            flag[i] = false;
            used[ str[i] - '0' ] = false;

            dfs( depth + 1 , now + str[i] );
            flag[i] = true;

        }
    }
    return;
}



int main(){

    int t;
    cin >> t;

    while( t-- ){

        memset( flag, true, sizeof(flag) );

        cin >> str >> d;
        n = str.size();
        quantity = 0;

        dfs( 0, "" );

        cout << quantity << endl;
        str.clear();
    }
}