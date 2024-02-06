from collections import deque
import sys

def cost(id, a, y, b, graph, n):
    dist = [sys.maxsize] * n
    q = deque()
    for i in range(id + 1):
        q.append(a[i])
        dist[a[i]] = 0
    while q:
        u = q.popleft()
        for v in graph[u]:
            if dist[v] == sys.maxsize:
                dist[v] = dist[u] + 1
                q.append(v)
    res = 0
    for i in range(y):
        res += dist[b[i]]
    return res

def reachQuickly(n, m, edges, x, a, y, b):
    graph = [[] for _ in range(n)]
    for edge in edges:
        u, v = edge
        graph[u].append(v)
        graph[v].append(u)
    mn = cost(x - 1, a, y, b, graph, n)
    l, r = 0, x - 1
    while l < r:
        mid = (l + r) // 2
        if cost(mid, a, y, b, graph, n) == mn:
            r = mid
        else:
            l = mid + 1
    return l

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        edges = [list(map(int, input().split())) for _ in range(m)]
        x, y = map(int, input().split())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        print(reachQuickly(n, m, edges, x, a, y, b))
