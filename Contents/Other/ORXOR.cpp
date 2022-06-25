/* 如何切區段，之所以要1<<n是為了可以跑000~111
i = 0，binary i = 000
0 : 1 5 7 
i = 1，binary i = 001
1 : 1 5 7
i = 2，binary i = 010，看得出來切了一刀
2 : 1 | 5 7
i = 3，binary i = 011
3 : 1 | 5 7
i = 4，binary i = 100，為了要切在index=2，所以才要1<<j
4 : 1 5 | 7
i = 5，binary i = 101
5 : 1 5 | 7
i = 6，binary i = 110
6 : 1 | 5 | 7
i = 7，binary i = 111
7 : 1 | 5 | 7
可以觀察出來，前兩位 bit 是 1 時代表的意義是切在哪裡*/
int n;
int num[20+7];
memset(num, 0, sizeof(num));
cin >> n;
for(int i = 1; i <= n; i++){
    cin >> num[i];
}
int mini = 2147483647; // 不知道為甚麼只有 2147483647 給過
// 1 << n = n * 2 
for(int i = 0; i < (1 << n); i++){
    int XOR = 0, OR = 0;
    for(int j = 1; j <= n; j++){
        OR |= num[j];
        if((i & (1 << j))){
            XOR ^= OR;
            OR = 0;
        }
    }
    XOR ^= OR;
    mini = min(mini, XOR);
}
cout << mini << endl;