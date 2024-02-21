from bisect import bisect_right
from math import log2
import sys


def build_sparse_table(a, n):
    LG = int(log2(n)) + 1
    st = [[0] * (n + 1) for _ in range(LG)]
    for i in range(n):
        st[0][i] = a[i]
    for i in range(1, LG):
        for j in range(n + 1 - (1 << i)):
            st[i][j] = st[i-1][j] | st[i-1][j + (1 << (i - 1))]
    return st

def query(st, L, R):
    lg = int(log2(R - L + 1))
    return st[lg][L] | st[lg][R - (1 << lg) + 1]

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    st = build_sparse_table(a, n)

    c = 0
    for i in range(n):
        j = i
        res = 0
        while j < n:
            res |= a[j]
            lo, hi = j, n - 1
            ind = j
            while lo <= hi:
                mid = (lo + hi) // 2
                if query(st, i, mid) > res:
                    hi = mid - 1
                else:
                    ind = mid
                    lo = mid + 1
            if bin(res).count('1') % 2 == 1:
                c += (ind - j + 1)
            j = ind + 1
    print(c)

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solve()
