// 卢卡斯定理 C(n, m) % p

typedef long long ll;

ll C(ll n, ll m, ll p) {
    static ll mem[1007][1007];
    if (mem[n][m]) {
        return mem[n][m];
    } else {
        if (m == 0 || m == n) {
            return mem[n][m] = 1;
        }

        return mem[n][m] = (C(n - 1, m, p) + C(n - 1, m - 1, p)) % p;
    }
}

static ll lucas_mem[1007][1007];
ll lucas(const ll n, const ll m, const ll p) {
    if (lucas_mem[n][m] >= 0) {
        return lucas_mem[n][m];
    }

    ll t = 1, a = n, b = m;
    while (t && a >= b) {
        if (a == b || b == 0) {
            return lucas_mem[n][m] = t;
        }

        t *= C(a % p, b % p, p);
        a /= p, b /= p;
    }
    return lucas_mem[n][m] = 0;
}

// memset(lucas_mem, -1, sizeof(lucas_mem));