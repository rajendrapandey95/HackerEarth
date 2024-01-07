import math
import sys

def bit(x):
    ans = 0
    while x:
        x //= 2
        ans += 1
    return ans

def check(d, x):
    if bit(x // d) <= bit(d):
        return True
    return False

def solve(x):
    l, r = 1, int(math.sqrt(x))
    while l < r:
        m = (l + r) // 2
        if check(m, x):
            r = m
        else:
            l = m + 1
    if not check(l, x):
        return l + 1
    else:
        return l

if __name__ == "__main__":
    if len(sys.argv) == 2 or len(sys.argv) == 3:
        sys.stdin = open(sys.argv[1], "r")
    if len(sys.argv) == 3:
        sys.stdout = open(sys.argv[2], "w")

    t = int(input())
    assert 1 <= t <= 10**6

    for _ in range(t):
        x = int(input())
        assert 1 <= x <= 10**12
        tp = solve(x)
        print(x - tp + 1)
