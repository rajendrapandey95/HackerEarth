from collections import defaultdict


def root(i):
    while Arr[i] != i:
        Arr[i] = Arr[Arr[i]]
        i = Arr[i]
    return i


def weighted_union(A, B):
    root_A = root(A)
    root_B = root(B)
    if root_A == root_B:
        return
    if node[root_A] < node[root_B]:
        Arr[root_A] = Arr[root_B]
        node[root_B] += node[root_A]
    else:
        Arr[root_B] = Arr[root_A]
        node[root_A] += node[root_B]


def solve():
    n = int(input())
    for i in range(n + 1):
        Arr[i] = i
        node[i] = 1

    v = []
    for _ in range(n):
        x, y = map(int, input().split())
        v.append((x, y))

    val = []
    for i in range(n):
        for j in range(i + 1, n):
            a = (v[i][0] - v[j][0]) ** 2 + (v[i][1] - v[j][1]) ** 2
            val.append((a, (i, j)))

    val.sort()
    ans = 0
    for i in val:
        if root(i[1][0]) != root(i[1][1]):
            ans += i[0]
            weighted_union(i[1][0], i[1][1])

    print(ans)


if __name__ == "__main__":
    Arr = {}
    node = {}
    solve()
