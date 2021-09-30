int main(){
    
    int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    string week[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    
    int n;
    cin >> n;
    while( n-- ){
        
        int m, d;
        cin >> m >> d;
        int w = 4;

        for( int i = 0; i<m-1 ; i++ )
            w += month[i];
            
        cout << week[ ( w + d )% 7 ] << endl;
    }
}