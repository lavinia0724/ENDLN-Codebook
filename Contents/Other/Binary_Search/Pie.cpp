/* binary search with double*/
const int maxn = 1e4+5;
int n, f;
int pie[maxn];
double binary_search(double lef, double rig){
    if((rig - lef) < 1e-6) return lef;
    double mid = (lef + rig) / 2.0;
    int total = 0;
    for(int i = 0; i < n; ++i)
        total += (pie[i] * pie[i] * acos(-1)) / mid;
    if(total < f+1)
        return binary_search(lef, mid);
    else
        return binary_search(mid, rig);
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> f;
        double mini = 0x3f3f3f3f;
        for(int i = 0; i < n; ++i){
            cin >> pie[i];
            double pie_now = pie[i] * pie[i] * acos(-1);
            mini = max(mini, pie_now);
        }
        cout << fixed << setprecision(4) << binary_search(0.0, mini) << endl;
    }
}