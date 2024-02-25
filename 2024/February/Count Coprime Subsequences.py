from collections import defaultdict

M = 10 ** 9 + 7
MAX = 1 + 100000

v = [False] * MAX
sp = [0] * MAX

for i in range(2, MAX, 2):
    sp[i] = 2

for i in range(3, MAX, 2):
    if not v[i]:
        sp[i] = i
        j = i
        while j * i < MAX:
            if not v[j * i]:
                v[j * i] = True
                sp[j * i] = i
            j += 2

squareFreeFactors = [[] for _ in range(MAX)]

def getSquareFreeFactors(val):
    if len(squareFreeFactors[val]) > 0:
        return squareFreeFactors[val]
    curr = val
    primes = []
    while curr > 1:
        if len(primes) == 0 or sp[curr] != primes[-1]:
            primes.append(sp[curr])
        curr //= sp[curr]
    m = len(primes)
    for mask in range(1, 1 << m):
        p = 1
        sign = -1
        for i in range(m):
            if mask & (1 << i):
                p *= primes[i]
                sign *= -1
        squareFreeFactors[val].append((p, sign))
    return squareFreeFactors[val]

def count(arr):
    res = 0
    dp = defaultdict(int)
    for el in arr:
        currctr = res + 1
        for p, sign in getSquareFreeFactors(el):
            currctr -= dp[p] * sign
        for p, sign in getSquareFreeFactors(el):
            dp[p] = (M + (dp[p] + currctr) % M) % M
        res += currctr
        res %= M
    return res

t = int(input())

for _ in range(t):
    N = int(input())
    arr = list(map(int, input().split()))
    print(count(arr))
