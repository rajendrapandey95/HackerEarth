MOD = 10**9 + 7
INF = 1011111111
LLINF = 1000111000111000111
EPS = 1e-10
PI = 3.14159265358979323

def powm(base, exp, mod=MOD):
    ans = 1
    while exp:
        if exp & 1:
            ans = (ans * base) % mod
        exp >>= 1
        base = (base * base) % mod
    return ans

def main():
    n = int(input())
    ans = 0

    for _ in range(n):
        w, h = map(int, input().split())
        if 10 * w >= 16 * h and 10 * w <= 17 * h:
            ans += 1
        elif 10 * h >= 16 * w and 10 * h <= 17 * w:
            ans += 1
        else:
            continue

    print(ans)

if __name__ == "__main__":
    main()
