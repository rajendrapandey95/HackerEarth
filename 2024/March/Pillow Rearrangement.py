import sys
sys.setrecursionlimit(10**6)

MOD = 10**9 + 7

def pow(a, b, mod):
    x = 1
    y = a
    while b > 0:
        if b % 2 == 1:
            x = (x * y) % mod
        y = (y * y) % mod
        b //= 2
    return x

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def lcm(a, b):
    return (a * b) // gcd(a, b)

def mod_exp(b, p, m):
    x = 1
    while p:
        if p & 1:
            x = (x * b) % m
        b = (b * b) % m
        p //= 2
    return x

def invFermat(a, p):
    return mod_exp(a, p - 2, p)

def exp(b, p):
    x = 1
    while p:
        if p & 1:
            x = (x * b)
        b = (b * b)
        p //= 2
    return x

def tostring(number):
    return str(number)

def toint(s):
    return int(s)

def precomp():
    facts = [0] * (maxm)
    invfacts = [0] * (maxm)
    numbersinverse = [0] * (maxm)

    facts[0] = facts[1] = 1
    for i in range(2, maxm):
        facts[i] = (i * facts[i - 1]) % MOD

    numbersinverse[0] = numbersinverse[1] = 1
    for i in range(2, maxm):
        numbersinverse[i] = numbersinverse[MOD % i] * (MOD - MOD // i) % MOD

    invfacts[0] = invfacts[1] = 1
    for i in range(2, maxm):
        invfacts[i] = (numbersinverse[i] * invfacts[i - 1]) % MOD

    return facts, invfacts, numbersinverse

def ways(n, r):
    f1 = facts[n]
    f2 = invfacts[r]
    f3 = invfacts[n - r]
    f1 = (f1 * f2) % MOD
    f1 = (f1 * f3) % MOD
    return f1

def solve():
    n, k = map(int, input().split())

    if n == 2 and k == 2:
        print("1")
        return

    ans = 0
    ok = min(n - 1, k)
    for i in range(ok + 1):
        ans = (ans + ((ways(n, i) * ways(n - 1, n - i - 1)) % MOD)) % MOD

    print(ans)

if __name__ == "__main__":
    maxm = 10**5 + 5
    facts, invfacts, numbersinverse = precomp()

    t = int(input())
    for _ in range(t):
        solve()
