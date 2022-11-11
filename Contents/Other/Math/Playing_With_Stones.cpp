/* Nim Game - SG 函數 */
long long int SG(long long int n){
    return n % 2 == 0 ? n/2 : SG(n/2);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long int a, v = 0;
        for(int i = 0; i < n; ++i){
            cin >> a;
            v ^= SG(a);
        }
        if(v) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}