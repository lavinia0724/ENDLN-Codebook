int main(){

    while(getline(cin,str1) && getline(cin, str2)){

        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        
        deque<char> dq;
        dq.clear();

        // set_intersection 在 C++ 中查詢集合交集
        // ex str1 = {1,2,3,4,5,6,7,8}, str2 = {5,7,9,10}
        // output = 5 7
        // set_intersection( 字串1頭, 字串1尾, 字串2頭, 字串2尾, 比較完要放進的地方 )
        set_intersection(str1.begin(), str1.end(), str2.begin(), str2.end(), insert_iterator<deque<char>>(dq,dq.begin()));

        for( int i=0; i<dq.size(); i++){

            cout<<dq[i];
            
        }
        cout << endl;

    }
}