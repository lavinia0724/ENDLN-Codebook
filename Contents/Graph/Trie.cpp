/* Trie 字典樹 */
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
            for(int j = 0; j < space; ++j){
                cout << " ";
            }
            cout << i->first << endl;
            put(i->second, space + 1);
        }
    }
}tree;