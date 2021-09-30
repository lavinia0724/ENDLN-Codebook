void bfs( int xn, int yn ){

    int xx, yx;

    // 從 -d 到 d 之間的所有格子
    // 因為起始點是中心，所以要用 -d ~ d 的方式算點
    for( int i = 0 - d; i <= d; i++ ){
        for( int k = 0 - d; k <= d; k++ ){

            xx = xn + i;
            yx = yn + k;

            if( xx >= 0 && xx < 1025 && yx >= 0 && yx < 1025 ){
                
                maxi[ xx ][ yx ] += rat[ xn ][ yn ];
                
                if( maxi[ xx ][ yx ] > maxm[2] ){
                    maxm[0] = xx;
                    maxm[1] = yx;
                    maxm[2] = maxi[ xx ][ yx ];
                }
            }
        }
    }
}

int main(){

    int t;
    cin >> t;

    while( t-- ){

        memset( rat, 0, sizeof(rat) );
        memset( maxi, 0, sizeof(maxi) );
        memset( check, 0, sizeof(check) );
        memset( maxm, 0, sizeof(maxm) );

        cin >> d >> n;
        int num = 0;

        for( int i = 0; i < n; i++ ){

            int a, b;
            cin >> a >> b;
            cin >> rat[a][b];

            check[num][0] = a;
            check[num][1] = b;
            num++;

        }

        for( int i = 0; i < num; i++ ){
            bfs( check[i][0], check[i][1] );
        }

       for( int i = 0; i < 3; i++ ){

           if( i != 2 ){
               cout << maxm[i] << " ";
           }
           else{
               cout << maxm[i] << endl;
           }
       }
    }
}