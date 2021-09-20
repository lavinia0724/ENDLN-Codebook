int GCD(int a, int b){
    if (b == 0){
        return a;
    }
    return GCD(b, a % b);
}

int LCM = a / GCD(a, b) * b;