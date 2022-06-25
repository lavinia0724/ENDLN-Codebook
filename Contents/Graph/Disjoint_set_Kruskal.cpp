struct Edge{
    int u, v, w;
    // 用權重排序 由大到小
    bool operator < (const Edge &other) const{
        return w > other.w;
    }
}edge[maxn];
// disjoint set
int find(int x){
	if(parent[x] < 0){
		return x;
	}
	else{
		return parent[x] = find(parent[x]);
	}
}
void unite(int a, int b){
	a = find(a);
	b = find(b);

	if(a != b){
		if(parent[a] < parent[b]){
			parent[a] += parent[b];
			parent[b] = a;
		}
		else{
			parent[b] += parent[a];
			parent[a] = b;
		}
	}
}
void kruskal(){
    memset(parent, -1, sizeof(parent));
    sort(edge, edge + m);
    int i, j;
    for(i = 0, j = 0; i < n - 1 && j < m; i++){
        // 如果 u 和 v 的祖先相同, 則 j++ (祖先相同代表會產生環 所以不要)
        while(find(edge[j].u) == find(edge[j].v)) j++;
        // 若部會產生環 則讓兩點之間產生橋 (連接兩顆子生成樹)
        unite(edge[j].u, edge[j].v);
        j++;
    }
}