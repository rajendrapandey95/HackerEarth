from collections import defaultdict

def solve(N, wealth):
    m = defaultdict(int)
    ans = 0
    po = [1] + [3 ** i for i in range(1, 21)]

    for it in wealth:
        m[it] += 1
        for i in range(1, 21):
            ans += m[po[i] - it]

    return ans

if __name__ == "__main__":
    N = int(input())
    assert 1 <= N <= 300000

    wealth = list(map(int, input().split()))
    for w in wealth:
        h = 3 ** 20
        assert 1 <= w <= h

    out_ = solve(N, wealth)
    print(out_)
