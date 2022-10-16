/* 建議搭配 Other - Stammering_Aliens 食用*/
#define ull unsigned long long int
const int maxn = 40000+5;
const ull seed = 131;
ull pw[maxn], hhash[maxn], hhash2[maxn];
char str[maxn];
void init(){
    hhash[0] = 0;
    for(int i = len-1; i >= 0; --i)
        hhash[i] = (hhash[i+1] * seed + str[i]);
}