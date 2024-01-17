import sys

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
        p >>= 1
    return x

def invFermat(a, p):
    return mod_exp(a, p - 2, p)

def exp(b, p):
    x = 1
    while p:
        if p & 1:
            x *= b
        b *= b
        p >>= 1
    return x

def tostring(number):
    return str(number)

def toint(s):
    return int(s)

def checker(state):
    if state == visAll - 1:
        return 0
    if dp[state] != -1:
        return dp[state]
    rounds = dp_bits[state] // 2
    ans = 0
    for i in range(n):
        if (state & (1 << i)) == 0:
            for j in range(i + 1, n):
                if (state & (1 << j)) == 0:
                    score = (rounds + 1) * (a[i] & a[j])
                    new_mask = state | (1 << i) | (1 << j)
                    ans = max(ans, score + checker(new_mask))
    dp[state] = ans
    return ans

def solve():
    global n, a, k, visAll, dp_bits, dp
    n = int(input())
    a = list(map(int, input().split()))
    k = int(input())
    visAll = (1 << n)
    dp_bits = [0] * (visAll + 2)
    for i in range(visAll + 2):
        dp_bits[i] = bin(i).count('1')
    dp = [-1] * (visAll + 2)
    ans = checker(0)
    print(ans)

if __name__ == "__main__":
    solve()
