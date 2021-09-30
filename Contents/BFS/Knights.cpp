int row[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int column[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

int bfs(){
    
    chess[0][0] = letter_start;
    chess[0][1] = digit_start;
    visited[ letter_start ][ digit_start ] = true;

    for( int i = 0, knights = 1; i < knights; i++ ){

        letter_now = chess[i][0];
        digit_now = chess[i][1];

        if( letter_now == letter_end && digit_now == digit_end ){
            return step[ letter_now ][ digit_now ];
        }

        for( int j = 0; j < 8; j++ ){
            
            letter_next = letter_now + column[j];
            digit_next = digit_now + row[j];

            if( letter_next < 1 || digit_next < 1 || letter_next > 8 || digit_next > 8 || visited[ letter_next ][ digit_next ] ){            
                continue;
            }
            else{
                visited[ letter_next ][ digit_next ] = true;
                step[ letter_next ][ digit_next ] = step[ letter_now ][ digit_now ] + 1;

                chess[ knights ][0] = letter_next;
                chess[ knights ][1] = digit_next;

                knights++;
            }
        }
    }
    return -1;
}

int main(){

    while( cin >> letter1 >> digit_start >> letter2 >> digit_end ){
               
        letter_start = letter1 - 'a' + 1;
        letter_end = letter2 - 'a' + 1;

        for( int i = 0; i < 10; i++ ){
            for( int j = 0; j < 10; j++ ){        
                step[i][j] = 0;
                visited[i][j] = false;
            }
        }
        cout << bfs() << " knight moves." << endl;
    }
}