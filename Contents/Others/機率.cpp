int main(){

    int s, n, i;
    double p, p2, ans;
    cin >> s;

    while( s-- ){
        
        cin >> n >> p >> i;
        p2 = pow( 1.0 - p , n );
        
        if( p2 == 1){

            cout << "0.0000" << endl;
            continue;

        }

        //第i個人成功的機率 / 全部的人有機會成功的機率(1-全部人都失敗)
        ans = p * pow( 1.0 - p , i-1 ) / ( 1.0 - pow( 1.0 - p , n ) );
        cout << fixed << setprecision(4) << ans <<endl;
    }
}