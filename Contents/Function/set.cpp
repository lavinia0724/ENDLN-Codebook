int main(){
    set<int> st {1, 6, 8}; // 直接初始化的寫法
    st.insert(1); // 也可以這樣寫就好
    set<int>::iterator iter;

    // 如果有找到，就會傳回正確的 iterator，否則傳回 st.end()
    if (iter != st.end()) {
        cout << "Found: " << *iter << endl;
    } else {
        cout << "Not found." << endl;
    }
    // cout: Found: 6

    // 取值：使用iterator
    x = *st.begin(); // set 中的第一個元素(最小的元素)
    x = *st.rbegin(); // set 中的最後一個元素(最大的元素)

    // search
    iter = st.find(6);
    auto it = st.find(x); // binary search, O(log(N))
    auto it = st.lower_bound(x); // binary search, O(log(N))
    auto it = st.upper_bound(x); // binary search, O(log(N))

    st.clear();
}