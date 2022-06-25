/* uper_bound ex:
10 20 30 30 40 50
upper_bound for element 30 is at index 4
lower_bound ex:
10 20 30 40 50
lower_bound for element 30 at index 2 */
int t;
cin >> t;
while(t--){
    int n, l, r;
    vector<int> v;
    cin >> n >> l >> r;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        v.emplace_back(num);
    }
    sort(v.begin(), v.end());
    long long int ans = 0;
    for(int i = 0; i < n; i++){
        ans += (upper_bound(v.begin() + i + 1, v.end(), r - v[i]) - lower_bound(v.begin() + i + 1, v.end(), l - v[i]));
    }
    cout << ans << endl;
}