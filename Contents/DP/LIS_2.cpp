int LIS(vector<int> &a){
    int len[a.size()];
    for(int i = 0; i < a.size(); ++i) len[i] = 1;
    int maxi = -1;
    for(int i = 0; i < a.size(); ++i)
        for(int j = i + 1; j < a.size(); ++j)
            if(a[i] <= a[j]) len[j] = max(len[j], len[i] + 1);

    for(int i = 0; i < a.size(); ++i)
        maxi = max(maxi, len[i]);
    return maxi;
}