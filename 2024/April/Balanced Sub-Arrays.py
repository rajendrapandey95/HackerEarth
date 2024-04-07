def ceil(a, b):
    return (a + b - 1) // b

t = int(input())
assert 1 <= t <= 200
sumN = 0

for _ in range(t):
    n = int(input())
    assert 1 <= n <= 10**5
    sumN += n
    assert sumN <= 10**6
    arr = [int(x) for x in input().split()]
    for i in arr:
        assert 1 <= i <= 10**5
    sums = [[0, 0] for _ in range(n + 1)]
    sums[0][arr[0] % 2] = 1
    ans = 1
    last_even = -1 if arr[0] % 2 else 0
    for i in range(1, n):
        if not arr[i] % 2:
            last_even = i
        sums[i][0] = sums[i - 1][arr[i] % 2] + ((arr[i] % 2) ^ 1)
        sums[i][1] = sums[i - 1][(arr[i] % 2) ^ 1] + (arr[i] % 2)
        ans += sums[last_even][(i - last_even) % 2] + ceil(i - last_even, 2)
    print(ans)
