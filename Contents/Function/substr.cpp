int main(){
    string str; //abcdef
    cin >> str;
    string tmp;
    tmp = str.substr(0, 2); //ab
    str = str.substr(2); //cdef
    cout << tmp << " " << str;
    return 0;
}
