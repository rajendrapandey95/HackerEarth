import heapq

def solve_tower(N, a):
    ans = []
    done = N
    pq = []
    heapq.heapify(pq)
    for x in a:
        heapq.heappush(pq, -x)
        aux = []
        while pq and -pq[0] == done:
            aux.append(done)
            heapq.heappop(pq)
            done -= 1
        ans.append(aux)
    a.sort()
    a = list(dict.fromkeys(a))
    assert len(a) == N
    return ans

def main():
    N = int(input())
    assert 1 <= N <= 10**6
    a = list(map(int, input().split()))
    assert len(a) == N

    out_ = solve_tower(N, a)
    for row in out_:
        print(*row)

if __name__ == "__main__":
    main()
