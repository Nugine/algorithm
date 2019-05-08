// 快速幂

int qpow(int b, int p) {
    int r = 1;
    while (p) {
        if (p & 1) {
            r *= b;
        }
        b *= b;
        p >>= 1;
    }
    return r;
}

int qpow(int b, int p, int m) {
    int r = 1;
    b %= m;
    while (p) {
        if (p & 1) {
            r *= b;
            r %= m;
        }
        b *= b;
        b %= m;
        p >>= 1;
    }
    return r;
}