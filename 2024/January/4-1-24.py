from collections import defaultdict

k, q = map(int, input().split())

def path(v):
    ans = [v]
    while v != 1:
        v //= k
        ans += [v]
    return ans

def lca(v, u):
    s = set(path(v))
    for x in path(u):
        if x in s:
            return x

weight_to_par = defaultdict(lambda: 1)

while q > 0:
    q -= 1
    query = list(map(int, input().split()))
    if query[0] == 1:
        v, u = query[1:]
        ans = 0
        p = lca(v, u)
        while v != p:
            ans += weight_to_par[v]
            v //= k
        while u != p:
            ans += weight_to_par[u]
            u //= k
        print(ans)
    else:
        v, u, w = query[1:]
        p = lca(v, u)
        while v != p:
            weight_to_par[v] += w
            v //= k
        while u != p:
            weight_to_par[u] += w
            u //= k
