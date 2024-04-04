t = int(input())
while t > 0:
    t -= 1
    n, k = map(int, input().split())
    s = sum(map(int, input().split()))
    print(max(0, s // (k + 1) - n + 1))
