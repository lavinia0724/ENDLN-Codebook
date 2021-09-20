int Find(int x) {
    if (x == p[x])
        return x;
    return p[x] = find(p[x]);
}

void Uni(int a, int b){

    a = Find(a);
    b = Find(b);

    if (a == b)
        return;
    if (p[a] < p[b]){
        p[a] = p[a] + p[b];
    }
    p[b] = a;
}

int main(){

    // initial
    for(i = 0; i < N; i++){
        p[i] = -1;
    }

    // input and union
    for(i = 0; i < M; i++){
        cin >> a >> b;
        Uni(a, b);
    }
}