vector<int> list[5];

void Adjacency_List(){

    for (int i = 0; i < 5; i++)
        list[i].clear();
 
    int a, b;   // start & end of an edge

    while (cin >> a >> b)
        list[a].push_back(b);
        // list[b].push_back(a);
}