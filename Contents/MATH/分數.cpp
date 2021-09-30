#include<iostream>
using namespace std;

// 1/k = 1/x + 1/y
// 給你 k，請你寫一個程式找出所有的 x 和 y
int main(){

    int n;
    while(cin>>n){

        int i;
        int N[10000+5][2]={0};
        int flag=0;

        for(i=n+1; i<= 2*n; i++){

            int r = i-n;

            if((n*i)% r ==0){

                N[flag][0]= (n*i)/r;
                N[flag][1]= i;
                flag++;

            }
        }

        cout<< flag << endl;
        for(i=0; i<flag; i++){
            cout<< "1/" << n << " = 1/" << N[i][0] << " + 1/" << N[i][1] << endl;   
        }
    }
    return 0;
}