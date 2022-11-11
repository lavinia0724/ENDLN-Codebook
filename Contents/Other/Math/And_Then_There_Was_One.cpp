/* 環狀取石頭更新
f(1)=0
f(i)=(f(i-1)+k)%i
f(n)=(f(n-1)+m)%n
最後石頭編號: f(n)+1=1 */
const int maxn = 10000+5;
int f[maxn];
int main(){
    int n, k, m;
    while(cin >> n >> k >> m && n && k && m){
        f[1] = 0;
        // i 是剩下的石頭數量
        for(int i = 2; i < n; ++i){
            f[i] = (f[i-1] + k) % i;
        }
        f[n] = (f[n-1] + m) % n;
        cout << f[n] + 1 << endl;
    }
}