/*數論*/
int main(){
    long long int n, m;
    while(cin >> n >> m && (n >= 0) && (m >= 0)){
        long long int total1 = 0, total2 = 0;
        long long int ten = 1, tmp = n-1;
        while(tmp >= 10){
            if(tmp % 10 == 0){
                tmp /= 10;
                total1 += (tmp - 1) * ten + ((n-1) % ten) + 1;
            }
            else{
                tmp /= 10;
                total1 += tmp * ten;
            }
            ten *= 10;
        }
        ten = 1; tmp = m;
        while(tmp >= 10){
            if(tmp % 10 == 0){
                tmp /= 10;
                total2 += (tmp - 1) * ten + (m % ten) + 1;
            }
            else{
                tmp /= 10;
                total2 += tmp * ten;
            }
            ten *= 10;
        }
        if(n == 0) total1--;
        cout << total2 - total1 << endl;
    }
}