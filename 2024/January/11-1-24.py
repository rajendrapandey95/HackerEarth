def double_beauty(n, k, a):
    # Sorting the array in non-increasing order.
    a.sort(reverse=True)

    # Initializing 'ans' with 0.
    ans = 0

    # Calculating 'ans'.
    for i in range(k):
        ans += a[i]

    ans *= 2

    # We are returning the answer here.
    return ans


if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        n, k = map(int, input().split())
        a = list(map(int, input().split()))

        print(double_beauty(n, k, a))
