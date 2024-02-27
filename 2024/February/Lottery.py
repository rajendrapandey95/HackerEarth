import sys

# To make input and output more efficient
input = sys.stdin.readline
print = sys.stdout.write

mod = 1000000007

class DSU:
    def __init__(self, n):
        self.par = [-1] * n
        self.f = [0] * n
        self.sz = [1] * n

    def get(self, x):
        if self.par[x] == -1:
            return x
        self.par[x] = self.get(self.par[x])
        return self.par[x]

    def unite(self, x, y):
        x = self.get(x)
        y = self.get(y)

        if x == y:
            if self.f[x]:
                return False
            self.f[x] = True
            return True

        if self.f[x] and self.f[y]:
            return False

        if self.sz[x] > self.sz[y]:
            x, y = y, x

        self.sz[y] += self.sz[x]

        if self.f[y] == 0 and self.f[x] == 1:
            self.f[y] = 1

        self.par[x] = y
        return True

def main():
    # Fast IO
    t = int(input())
    for _ in range(t):
        k, n, m = map(int, input().split())
        ad = []
        for _ in range(k):
            u, v, w = map(int, input().split())
            u -= 1
            v += n - 1
            ad.append((u, v, w))
        ad.sort(key=lambda x: x[2], reverse=True)

        nodes = n + m
        d = DSU(nodes)
        ans = 0

        for u, v, w in ad:
            if d.unite(u, v):
                ans += w

        print(str(ans) + '\n')

if __name__ == "__main__":
    main()
