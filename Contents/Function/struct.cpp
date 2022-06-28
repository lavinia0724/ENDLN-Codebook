struct area{
    int a, b;
    bool operator<(const area rhs) const{
        return a > rhs.a || ( a == a && b > rhs.b);
    }
    bool operator!=(const area rhs) const{
        return a != rhs.a || b != rhs.b;
    }
};