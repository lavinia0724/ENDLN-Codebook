'''
Mod
pow(x, y, z) = x^y % z
'''
# python 如何讀取直到 EOF 用 try except
try:
    while True:
        # input().split() 用空格切開讀取一整行
        # map (型態, input().split()) 才能把值全讀成 int
        B, P, M = map(int, input().split())
        print(pow(B, P, M))
except EOFError:
    exit 