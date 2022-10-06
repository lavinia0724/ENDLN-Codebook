int main(){
    string str;
    while(cin >> str){
        // substr 取 str idx 2~4 的值
        cout << str.substr(2, 4) << endl;
        // substr 取 str idx 2 以後的所有值
        cout << str.substr(2) << endl;
        
        string subst;
        cin >> subst;
        // str.append 連接字串
        cout << str.append(subst) << endl;
        
        char s[100], ss[100];
        cin >> s >> ss;
        
        char *p;
        // strstr 回傳在s裡找到ss後的整個字串(從 ss idx 0 到結束)
        p = strstr(s, ss);
        cout << p << endl;
        // strstr 也可以單純用來找字串
        if(p != NULL) cout << "yes" << endl;
        else cout << "no" << enld;
    }
}