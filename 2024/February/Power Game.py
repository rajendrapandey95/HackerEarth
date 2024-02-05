from typing import List, Tuple

class Solution:
    def __init__(self):
        self.MOD = 10**9 + 7
        self.MOD2 = 998244353
        self.PI = 2 * acos(0.0)

    def gcd(self, a: int, b: int) -> int:
        return a if b == 0 else self.gcd(b, a % b)

    def lcm(self, a: int, b: int) -> int:
        return a * (b // self.gcd(a, b))

    def mod_exp(self, b: int, p: int, m: int) -> int:
        x = 1
        while p:
            if p & 1:
                x = (x * b) % m
            b = (b * b) % m
            p >>= 1
        return x

    def invFermat(self, a: int, p: int) -> int:
        return self.mod_exp(a, p - 2, p)

    def exp(self, b: int, p: int) -> int:
        x = 1
        while p:
            if p & 1:
                x = (x * b)
            b = (b * b)
            p >>= 1
        return x

    def dfs(self, v: int, p: int, edges: List[List[Tuple[int, int]]], visited: List[bool], tin: List[int],
            low: List[int], timer: List[int], bridgelen: List[int]):
        visited[v] = True
        tin[v] = low[v] = timer[0]

        for to in edges[v]:
            if to[0] == p:
                continue
            if visited[to[0]]:
                low[v] = min(low[v], tin[to[0]])
            else:
                self.dfs(to[0], v, edges, visited, tin, low, timer, bridgelen)
                low[v] = min(low[v], low[to[0]])

                if low[to[0]] > tin[v]:
                    bridgelen.append(to[1])

    def find_bridges(self, n: int, edges: List[List[Tuple[int, int]]]) -> List[int]:
        visited = [False] * n
        tin = [-1] * n
        low = [-1] * n
        timer = [0]
        bridgelen = []
        
        for i in range(n):
            if not visited[i]:
                self.dfs(i, -1, edges, visited, tin, low, timer, bridgelen)

        return bridgelen

    def solve(self):
        n, m = map(int, input().split())
        edges = [[] for _ in range(3 * 10**5 + 5)]
        bridgelen = []

        me = list(map(int, input().split()))

        for _ in range(m):
            x, y = map(int, input().split())
            x -= 1
            y -= 1
            edges[x].append((y, me[_]))
            edges[y].append((x, me[_]))

        bridgelen = self.find_bridges(n, edges)
        bridgelen.sort()

        minm1, minm2 = 0, 0
        ok = 0

        for x in bridgelen:
            if not ok:
                minm1 += x
            else:
                minm2 += x
            ok ^= 1

        maxm1, maxm2 = 0, 0
        ok = 0

        bridgelen.reverse()

        for x in bridgelen:
            if not ok:
                maxm1 += x
            else:
                maxm2 += x
            ok ^= 1

        maxm1 = max(maxm1, maxm2)
        minm1 = min(minm1, minm2)

        print(maxm1, minm1)


if __name__ == "__main__":
    Solution().solve()
