double calculate( int x1, int y1, int x2, int y2 ){
    
    // 計算兩點之間的距離
    // pow 次方 -> pow( 底數, 指數 )
    // sqrt 開根號 -> sqrt( 數 )
    return sqrt( pow( ( x1 - x2 ) , 2 ) + pow( ( y1 - y2 ) , 2 ) );

}

void dfs( int depth, double path ){

    if( depth == n ){
        if( path < shortest ){
            
            shortest = path;
            final_edge.clear();

            for( int i = 0; i < n; i++ ){            
                final_edge.push_back( x_now[ i ] );
                final_edge.push_back( y_now[ i ] );
            }
        }
        return;
    }

    // 這次的 dfs 要對每個點做開關 ( true or false )
    // 在做完一趟後 直接更改 depth - 1 的點後 去對 depth 的點 ( 改變末兩點 )
    // 第二趟時 跟改 depth - 2 的點後 先依輸入順序填入後面其他點 而後下幾輪再繼續排列
    for( int i = 0; i < n; i++ ){

        if( flag[i] ){

            flag[i] = false;

            x_now[ depth ] = x[i];
            y_now[ depth ] = y[i];

            if( depth == 0 ){
                dfs( depth + 1, 0 );
            }
            else{
                dfs( depth + 1, path + 16 + calculate( x_now[ depth ], y_now[ depth ], x_now[ depth - 1 ], y_now[ depth - 1 ] ) );            
            }      
            flag[i] = true;
        }
    }
}

int main(){

    int num = 1;

    while( cin >> n && n ){

        int edge;
        // 先隨便設個最小值
        shortest = 2147483647;
        for( int i = 0; i < n; i++ ){
            
            cin >> edge;
            x.push_back(edge);

            cin >> edge;
            y.push_back(edge);

            flag.insert( pair<int, bool>( i, true ) );
        }

        dfs( 0, 0 );

            ...
    }
}