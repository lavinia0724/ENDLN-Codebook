int Phi(int n){
    int ans = n;
    for (int i: p) {
        if (i * i > n){
            break;
        }
        if (n % i == 0){
            ans /= i;
            ans *= i - 1;
            while (n % i == 0){
                n /= i;
            }
        }
    }
    if (n != 1) {
        ans /= n;
        ans *= n - 1;
    }
    return ans;
}