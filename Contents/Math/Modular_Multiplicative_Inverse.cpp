// 乘法逆元
// c++
void exgcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

// python
def exgcd(a, b):
    if b == 0:
        x = 1
        y = 0
        return x, y
    x1, y1 = exgcd(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return x, y