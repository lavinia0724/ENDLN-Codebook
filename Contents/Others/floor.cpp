int main(){

    int a, b;
    while( cin >> a >> b  && ( a || b ) ){

        int aa, bb, check = 0;
        if( floor( sqrt(a) ) == sqrt(a) ){
            check = 1;
        }
        double count = 0;

        //floor -> 不大於 x 的最大整數 ( 浮點型 )
        count = floor( sqrt(b) ) - floor( sqrt(a) ) + check;
        
        cout << (int)count << endl;
    }
}