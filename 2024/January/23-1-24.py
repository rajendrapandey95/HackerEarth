def solve():
    n = int(input())
    q = int(input())
    v = []
    for i in range(q):
        l, r, a = map(int, input().split())
        v.append((l, r, a))
    
    v.sort()
    ans = -1
    lo, hi = 1, 10**12
    
    while lo <= hi:
        mid = (lo + hi) // 2
        f, l, r, c = 0, 10**18, 0, 0
        
        for i in v:
            if i[2] > mid:
                continue
            l = min(l, i[0])
            
            if f == 0:
                f = 1
                r = i[1]
            else:
                if (i[0] - r) > 1:
                    c = 1
                    break
                r = max(r, i[1])
        
        if c:
            lo = mid + 1
            continue
        
        if l == 1 and r == n:
            ans = mid
            hi = mid - 1
        else:
            lo = mid + 1
    
    print(ans)

if __name__ == "__main__":
    solve()
