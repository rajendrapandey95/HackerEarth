import math
from collections import defaultdict

MOD = 10**9 + 7

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def lcm(a, b):
    return a * (b // gcd(a, b))

def mod_exp(b, p, m):
    x = 1
    while p:
        if p & 1:
            x = (x * b) % m
        b = (b * b) % m
        p = p >> 1
    return x

def inv_fermat(a, p):
    return mod_exp(a, p - 2, p)

def to_string(number):
    return str(number)

def to_int(s):
    return int(s)

def sieve_of_eratosthenes(maxm):
    sieve = [i for i in range(maxm)]
    for i in range(2, maxm):
        if sieve[i] == i:
            for j in range(2 * i, maxm, i):
                sieve[j] = i
    return sieve

def solve():
    n = int(input())
    a = [0] + list(map(int, input().split()))  

    vis = [False] * (n + 1)
    for i in range(1, n + 1):
        vis[a[i]] = True

    for i in range(1, n + 1):
        if not vis[i]:
            print("-1")
            return

    ans = 1
    vis = [False] * (n + 1)
    freq = [0] * (n + 2)
    for i in range(1, n + 1):
        if not vis[i]:
            cnt = 0
            cur = i
            while not vis[cur]:
                vis[cur] = True
                cnt += 1
                cur = a[cur]

            while cnt > 1:
                prime_fact = sieve[cnt]
                ok = 0
                while cnt % prime_fact == 0:
                    ok += 1
                    cnt //= prime_fact
                freq[prime_fact] = max(freq[prime_fact], ok)

    for i in range(2, n + 1):
        for j in range(freq[i]):
            ans = (ans * i) % MOD

    print(ans)

if __name__ == "__main__":
    t = int(input())
    sieve = sieve_of_eratosthenes(10**5 + 2)

    for _ in range(t):
        solve()
