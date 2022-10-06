int main(){
    map<string, string> mp;
    map<string, string>::iterator iter;
    map<string, string>::reverse_iterator iter_r;

    mp.insert(pair<string, string>("r000", "zero"));

    mp["r123"] = "first";

    for(iter = mp.begin(); iter != mp.end(); iter++)
        cout<<iter->first<<" "<<iter->second<<endl;
    for(iter_r = mp.rbegin(); iter_r != mp.rend(); iter_r++)
        cout<<iter_r->first<<" "<<iter_r->second<<endl;

    iter = mp.find("r123");
    mp.erase(iter);

    iter = mp.find("r123");
    if(iter != mp.end())
       cout<<"Find, the value is "<<iter->second<<endl;
    else
       cout<<"Do not Find"<<endl;

    mp.clear();
    mp.erase(mp.begin(), mp.end());
}