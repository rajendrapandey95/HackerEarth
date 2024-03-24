from collections import defaultdict

n, k = map(int, input().split())
li = [int(x) for x in input().split()]

temp = []

for i in li:
    t = i % k
    temp.append([t, -i])

temp.sort(reverse=True)

for i in range(n):
    print(-temp[i][1], end=" ")
