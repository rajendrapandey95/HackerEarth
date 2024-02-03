class Dsu:
    def __init__(self, n):
        self.par = [-1] * n
    
    def root(self, v):
        return v if self.par[v] < 0 else self.root(self.par[v])
    
    def is_same_set(self, v, u):
        return self.root(v) == self.root(u)
    
    def merge(self, v, u):
        v, u = self.root(v), self.root(u)
        if v == u:
            return False
        self.par[u] += self.par[v]
        self.par[v] = u
        return True

def main():
    n, m = map(int, input().split())
    dsu = Dsu(n)
    
    v, u = [], []
    for i in range(m):
        vi, ui = map(int, input().split())
        v.append(vi - 1)
        u.append(ui - 1)

    a = list(map(int, input().split()))
    
    s, e = map(int, input().split())
    s, e = s - 1, e - 1
    
    lo, hi = -1, 10**6
    while hi - lo > 1:
        dsu = Dsu(n)
        mid = (lo + hi) // 2
        for i in range(m):
            if abs(a[v[i]] - a[u[i]]) <= mid:
                dsu.merge(v[i], u[i])
        
        if dsu.is_same_set(s, e):
            hi = mid
        else:
            lo = mid
    
    print(hi)

if __name__ == "__main__":
    main()
