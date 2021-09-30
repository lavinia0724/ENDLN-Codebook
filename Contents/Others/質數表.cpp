bool prime[1000000];

// memset: 對一段內存空間全部設置為某個字符 常用於初始化字串、陣列..
// memset( 陣列名稱, 初始化成甚麼, 範圍 )
    memset( prime, false, sizeof(prime) );
    memset( prime, true, 2);

    for( int i = 2; i < 1000000; i++ ){
        
        if( !prime[i] ){

            for( int j = i + i; j < 1000000; j += i ){

                prime[j] = true;

            }
        }
    }