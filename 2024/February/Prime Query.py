def solve():
    n = int(input())
    a = list(map(int, input().split()))

    zero = [0] * n
    one = [0] * n
    for i in range(n):
        if a[i] == 0:
            zero[i] = 1
        if a[i] == 1:
            one[i] = 1
        if i > 0:
            zero[i] += zero[i - 1]
            one[i] += one[i - 1]

    q = int(input())
    for _ in range(q):
        l, r = map(int, input().split())
        l -= 1
        r -= 1

        x = zero[r]
        if l > 0:
            x -= zero[l - 1]

        y = one[r]
        if l > 0:
            y -= one[l - 1]

        length = r - l + 1
        c = (length * (length - 1)) // 2
        c -= (x * (x - 1)) // 2
        c -= x * y

        print(c)

T = int(input())

for tc in range(1, T + 1):
    solve()
