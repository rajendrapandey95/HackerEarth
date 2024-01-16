mod = 1000000007

def add(a, b):
    return ((a % mod) + (b % mod)) % mod

def sub(a, b):
    return ((a % mod) - (b % mod) + mod) % mod

def mul(a, b):
    return ((a % mod) * (b % mod)) % mod

def binpow(a, b):
    res = 1
    while b > 0:
        if b & 1:
            res = mul(res, a)
        a = mul(a, a)
        b >>= 1
    return res

def inverse(x):
    return binpow(x, mod - 2)

t = int(input())

for _ in range(t):
    p, q, r = map(int, input().split())
    
    n = sub(binpow(r, p * q), 1)
    temp = sub(binpow(r, p), 1)
    m = mul(binpow(r, p * q), temp)
    res = mul(n, inverse(m))

    print(res)
