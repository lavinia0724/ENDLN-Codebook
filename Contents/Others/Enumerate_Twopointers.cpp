#include<bits/stdc++.h>
using namespace std;
//2021.09.14

int main(){

    long long int t;
    cin >> t;
    while( t-- ){

        long long int n;
        deque<int> snowflakes;
        set<long long int> difference;

        cin >> n;
        for( int i = 0; i < n; i++ ){

            int m;
            cin >> m;
            snowflakes.push_back(m);

        }
        int longest = 0;
        
        // 利用 L左指標 和 R右指標
        // 每次迭代右指標先往前一個位置
        for( int L = 0, R = 0; R < n; R++ ){

            // 利用 set.count 先確認 set 內是否有重複元素
            while( difference.count( snowflakes[R] ) ){

                // 如果有 利用 set.erase 和左指標
                // 將與 右指標重複的元素 以前的所有元素刪除
                difference.erase( snowflakes[ L++ ] );

            }

            difference.insert( snowflakes[R] );

            // std::max 可比較兩者之間誰大
            // max( 比較方1, 比較方2 ) 比較方可以不一定是 int 但一定要相同型態
            longest = max( longest, (int)difference.size() );
        }

        cout << longest << endl;    
        difference.clear();
        snowflakes.clear();
    }
}