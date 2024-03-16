def main():
    n, m, k = map(int, input().split())

    a = [[0] * m for _ in range(n)]
    lazy = [[0] * m for _ in range(n)]

    for i in range(n):
        a[i] = list(map(int, input().split()))

    for _ in range(k):
        r, c, s, d = map(int, input().split())
        r -= 1
        c -= 1
        for i in range(s):
            lazy[i + r][c] += d
            if c + s < m:
                lazy[i + r][c + s] -= d

    for i in range(n):
        for j in range(1, m):
            lazy[i][j] += lazy[i][j - 1]

    for i in range(n):
        for j in range(m):
            print(a[i][j] + lazy[i][j], end=" ")
        print()


if __name__ == "__main__":
    main()
