priority_queue<int, vector<int>, less<int>> //大到小
priority_queue<int, vector<int>, greater<int>> //小到大

int arr[] = {4, 5, 8, 3, 7, 1, 2, 6, 10, 9};
    sort(arr, arr+10);

vector<int> v;
sort(v.begin(), v.end()); //小到大

int cmp(int a, int b){
    return a > b;
}
sort(v.begin(), v.end(), cmp); //大到小
