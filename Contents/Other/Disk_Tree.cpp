/* Trie 字典樹 */
const int maxn = 50000+5;
struct Tire{
    int path;
    map<string, int> G[maxn];
    void init(){
        path = 1;
        G[0].clear();
    }
    void insert(string str){
        int u = 0;
        string word = "";
        for(int i = 0; i < str.size(); ++i){
            if(str[i] == '\\'){
                if(!G[u].count(word)){
                    G[path].clear();
                    G[u][word] = path++;
                }
                u = G[u][word];
                word = "";
            }
            else word += str[i];
        }
    }
    void put(int u, int space){
        for(auto i = G[u].begin(); i != G[u].end(); ++i){
            for(int j = 0; j < space; ++j)
                cout << " ";
            cout << i->first << endl;
            put(i->second, space + 1);
        }
    }
}tree;
int main(){
    int n;
    string str;
    while(cin >> n && n){
        tree.init();
        for(int i = 0; i < n; ++i){
            cin >> str;
            str += '\\';
            tree.insert(str);
        }
        tree.put(0, 0);
        cout << endl;
    }
}
