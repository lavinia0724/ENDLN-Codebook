int step[4][2] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };

deque< pair<int,int> > fn;
deque< pair<int,int> > joen;

void bfs_fire( int n ){

    for( int i = 0; i < 4 ; i++ ){

        int xx = fn[n].first + step[i][0];
        int yx = fn[n].second + step[i][1];

        if( xx > 0 && xx <= r && yx > 0 && yx <= c ){

            if( mp[ xx ][ yx ] == '.' ){
                mp[ xx ][ yx ] = 'F';
                fn.push_back( make_pair( xx, yx ) );
            }
        }
    }
    vis_f++;
}

void bfs_joe( int n ){

    for( int i = 0; i < 4; i++ ){
        
        int xx = joen[n].first + step[i][0];
        int yx = joen[n].second + step[i][1];

        if( mp[ xx ][ yx ] == '.' ){
            
            mp[ xx ][ yx ] = 'J';
            escape = true;
            joen.push_back( make_pair( xx, yx ) );
        }
        if( mp[ xx ][ yx ] == ' ' ){

            fin = true;
            break;
        }
    }
    vis_j++;
}

int main(){

    cin >> t;
    while( t-- ){

        cin >> r >> c;
        memset( mp, ' ', sizeof(mp) );

        while( !fn.empty() ){
            fn.pop_front();
        }
        while( !joen.empty() ){
            joen.pop_front();
        }

        for( int i = 1; i <= r; i++ ){
            for( int j = 1; j <= c; j++ ){

                cin >> mp[i][j];
                if( mp[i][j] == 'F' ){
                    fn.push_back( make_pair( i, j ) );
                }
                if( mp[i][j] == 'J' ){
                    joen.push_back( make_pair( i, j ) );
                }
            }
        }

        times = 0;
        escape = true;
        fin = false;

        vis_f = 0;
        vis_j = 0;

        while( escape ){

            escape = false;
            times++;
            max_f = fn.size();
            max_j = joen.size();

            for( int i = vis_f; i < max_f; i++ ){
                bfs_fire( i );
            }
            for( int i = vis_j; i < max_j; i++ ){
                bfs_joe( i );
            }

            if( fin ){
                cout << times << endl;
                break;
            }
        }

        if( !fin ){
            cout << "IMPOSSIBLE" << endl;
        }
        check++;
    }
}