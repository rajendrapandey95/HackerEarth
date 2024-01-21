def solve():
    n = int(input())
    freq = {}
    ans = 0

    # Read space-separated integers on a single line
    x_values = list(map(int, input().split()))

    for i in range(1, n + 1):
        x = x_values[i - 1]
        ans += freq.get(x ^ i, 0)
        freq[x ^ i] = freq.get(x ^ i, 0) + 1

    print(ans)


if __name__ == "__main__":
    t = int(input())
    
    for _ in range(t):
        solve()
