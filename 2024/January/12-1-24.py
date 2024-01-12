def swap_sum(n, k, a, b):
    v = []

    ans = 0

    for i in range(n):
        if a[i] < b[i]:
            v.append((b[i] - a[i], (b[i], a[i])))
        else:
            ans += a[i]

    v.sort(reverse=True)

    for i in range(min(k, len(v))):
        ans += v[i][1][0]

    for i in range(k, len(v)):
        ans += v[i][1][1]

    return ans


if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        n, k = map(int, input().split())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))

        result = swap_sum(n, k, a, b)
        print(result)
