int main(){

    int n;
    string country, name;

    map<string, int> m;
    map<string, int>::iterator it;

    cin>>n;
    while( n-- ){

        cin >> country ;
        getline(cin, name);
        it = m.find( country );

        if( it != m.end() ){
            m[ country ]++;
        }
        else{
            m.insert( pair<string, int>( country, 1) );
        }
    }
    for( auto i = m.begin(); i != m.end(); i++ ){
        cout << i->first << " " << i->second <<endl;
    }
}