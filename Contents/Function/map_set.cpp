.begin( ) // Return iterator to beginning 
.end( ) // Return iterator to end
.empty( ) // 檢查是否為空
.size( )  // 回傳大小
mp.insert(pair<char,int>('a',100))
st.insert(100) // 插入key、value
.erase( ) // 刪掉指定key和他的value 
.clear( ) // 清空整個 map 
m.find( )
cout << "a => " << mymap.find('a')->second << endl;
    // 找出 map 裡 key 有沒有在裡面，如果有的話會回傳元素所在的iterator，否則傳回隊尾
s.count() // 返回某個值元素在set的個數
while( !mymap.empty()){
    cout << mymap.begin()->first << " => " << mymap.begin()->second << endl;
    mymap.erase(mymap.begin());
}
for (auto it = mymap.begin(); it != mymap.end(); ++it)
    cout << it->first << " => " << it->second << endl;