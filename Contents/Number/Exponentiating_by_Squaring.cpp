T pow(int a, int b, int c){ // calculate a ^ b % c
    T ans = 1, tmp = a;
    for (; b; b >>= 1) {
        if (b & 1){ // b is odd
            ans = ans * tmp % c;
        }
        tmp = tmp * tmp % c;
    }
  return ans;
}