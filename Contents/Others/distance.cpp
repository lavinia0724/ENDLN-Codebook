double calculate( int x1, int y1, int x2, int y2 ){
    
    // 計算兩點之間的距離
    // pow 次方 -> pow( 底數, 指數 )
    // sqrt 開根號 -> sqrt( 數 )
    return sqrt( pow( ( x1 - x2 ) , 2 ) + pow( ( y1 - y2 ) , 2 ) );

}