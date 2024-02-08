from collections import defaultdict

N = 1000005
LG = 22

lvl = [0] * N
P = [[-1] * LG for _ in range(N)]
g = defaultdict(list)


def clear(n):
    global lvl, P, g
    for i in range(n + 1):
        lvl[i] = 0
        g[i].clear()
        for j in range(LG):
            P[i][j] = -1


def dfs(u, par):
    lvl[u] = 1 + lvl[par]
    P[u][0] = par
    for i in range(1, LG):
        if P[u][i - 1] != -1:
            P[u][i] = P[P[u][i - 1]][i - 1]
    for v in g[u]:
        if v == par:
            continue
        dfs(v, u)


def lca(u, v):
    if lvl[u] < lvl[v]:
        u, v = v, u

    lg = 0
    while (1 << lg) <= lvl[u]:
        lg += 1
    lg -= 1

    for i in range(lg, -1, -1):
        if lvl[u] - (1 << i) >= lvl[v]:
            u = P[u][i]

    if u == v:
        return u

    for i in range(lg, -1, -1):
        if P[u][i] != -1 and P[u][i] != P[v][i]:
            u = P[u][i]
            v = P[v][i]

    return P[u][0]


def dis(u, v):
    if lvl[u] < lvl[v]:
        u, v = v, u
    w = lca(u, v)
    return lvl[u] + lvl[v] - 2 * lvl[w]


def solve():
    global g
    n = int(input())
    clear(n)

    for _ in range(n - 1):
        x, y = map(int, input().split())
        g[x].append(y)
        g[y].append(x)

    dfs(1, 0)

    q = int(input())
    for _ in range(q):
        x, y = map(int, input().split())

        l = dis(x, y) + 1
        if l % 2 == 0:
            print("Yes")
        else:
            print("No")
            print(1, l)


def main():
    T = int(input())

    for _ in range(T):
        solve()


if __name__ == "__main__":
    main()
