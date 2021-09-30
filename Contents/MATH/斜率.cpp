// 八皇后 上下左右斜行皆不重複
int check( int x, int y ){

    for( int i = 0; i < x; i++ ){

        if( dq[1][i] == y ){
            return 0;
        }
        
        // 如果兩皇后在同一斜線上 其斜率為 1
        // 如果 x2 - x1 == y2 - y1 -> y2 - y1 / x2 - x1 == 1
        if( abs( x - i ) == abs( dq[1][i] - y ) ){
            return 0;
        }
        
    }
    return 1;
}