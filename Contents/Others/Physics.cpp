int main(){
    
    // s = vot + 1/2 at^2
    // v = vo + at
    // a = ( v - vo ) / t

    // vo = 0
    // a = v / t
    // s = 0 + 1/2 v/t 2t^2 = 1/2 v 4t = 2vt

    int v,t;
    while( cin >> v >> t ){
        int s;
        s =  2 * v * t ;
        cout << s << endl;
    }
}