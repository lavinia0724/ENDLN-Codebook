/* 數論畫圖 */
int main(){
    long long int n;
    long long int a, b;
    long long int p, q, r, s;
    cin >> n >> a >> b;
    cin >> p >> q >> r >> s;
    for(long long int i = p; i <= q; i++){
        for(long long int j = r; j <= s; j++)
            if(abs(i - a) == abs(j - b)) cout << '#';
            else cout << '.';
        cout << endl;
    }
}