def f(n, k):
    if n == 0:
        return 0
    res = n // k
    return f(n // k, k) + n * (n + 1) // 2 - (res * (res + 1) // 2) * k

def main():
    T = int(input())
    assert 1 <= T <= 300000
    for _ in range(T):
        n, k = map(int, input().split())
        assert n <= 10**9
        assert 2 <= k <= 10**9
        print(f(n, k))

if __name__ == "__main__":
    main()
