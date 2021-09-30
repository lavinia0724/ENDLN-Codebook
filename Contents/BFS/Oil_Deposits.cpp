int row[] = { 1, 1, 1, 0, -1, -1, -1, 0 };
int column[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

void bfs( int x_now, int y_now ){

    for( int j = 0; j < 8; j++ ){

        x_next = x_now + row[j];
        y_next = y_now + column[j];

        if( x_next < m && y_next < n && x_next >= 0 && y_next >= 0 && oil[ x_next ][ y_next ] == '@' ){

            // 此點已找過 就把他改成普通地板
            oil[ x_next ][ y_next ] = '*';
            bfs( x_next, y_next );
        }
    }  
    return;
}

int main(){

    while( cin >> m >> n && m && n ){

        memset( oil, '0', sizeof(oil) );
        ans = 0;

        for( int i = 0; i < m; i++ ){
            for( int j = 0; j < n; j++ ){
                cin >> oil[i][j];           
            }
        }

        for( int i = 0; i < m; i++ ){
            for( int j = 0; j < n; j++ ){
                
                if( oil[i][j] == '@' ){
                   ans++;
                   bfs( i, j );
                }

            }
        }
        cout << ans << endl;
    }   
}