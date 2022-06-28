import math
import operator

try:
    while(1):
        listx = []
        listx.append("...")
        list_s = sorted(listx) # 小到大
        list_s = sorted(listx, reverse = True) # 大到小
        # max(listx)
        # min(listx)
        # sum(listx)
        # len(listx)
        dicty = {}
        dicty[key] = "value"
        dicty= sorted(dicty.items()) # by key
        dicty= sorted(dicty.items(), key=operator.itemgetter(1)) # by value
        # EOF寫法
        # 階層 math.factorial(3) == 6
        # 絕對值 math.fabs(x)
        # 無條件進位 math.ceil(3.1) == 3
        # 無條件捨去 math.floor(2.9) == 2
        # C n 取 k math.comb(n, k)
        # math.gcd
        # math.lcm
        # e 次 x 幂 math.exp(x)
except EOFError:
    pass