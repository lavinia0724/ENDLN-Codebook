// 題目給定一個 N 進制 (2 <= N <= 62) 的數字 R，R 保證可以被 (N-1) 整除
// 求符合提議的最小 N
// 當 N = 62 時，用來表示62進制的字符為 0..9, A..Z, a..z。

int main(){

    // R = 265
    // = 2*N*N + 6*N + 5
    // = 2*N*(N-1+1) + 6*N + 5
    // = 2*N*(N-1) + 2*(N-1+1) + 6*(N-1+1) + 5
    // = 2*N*(N-1) + 2*(N-1) + 2 + 6*(N-1) + 6 + 5
    // = (2*N + 2 + 6)*(N-1) + (2 + 6 + 5)
    // because R % N-1 == 0
    // so (2+6+5) == N-1

    string str;
    while( getline( cin, str ) ){
        
        int tmp;
        int max = 1, sum = 0;
        bool flag = true;

        for( int i = 0; i < str.size(); i++ ){

            if( str[i] >= '0' && str[i] <= '9' ){
                tmp = str[i] - '0';
            }
            else if( str[i] >= 'A' && str[i] <= 'Z' ){
                tmp = str[i] - 'A' + 10;
            }
            else if( str[i] >= 'a' && str[i] <= 'z' ){
                tmp = str[i] - 'a' + 10 + 26;
            }
            else{
                continue;
            }

            if( tmp > max){
                max = tmp;
            }
            sum += tmp;
        }
        for( int i = max; i < 62; i++ ){
            if( !( sum % i ) ){
                cout << i + 1 << endl;
                flag = false;
                break;
            }
        }
        if( flag ){
            cout << "such number is impossible!" << endl;
        }
        str.clear();
    }
}