n = int(input().strip())
a = list(map(int, input().strip().split()))

mp1 = {}
mp2 = {}

for i in range(n):
    mp1[a[i] + (i + 1) ** 2] = mp1.get(a[i] + (i + 1) ** 2, 0) + 1

for i in range(n):
    mp2[a[i] - (i + 1) ** 2] = mp2.get(a[i] - (i + 1) ** 2, 0) + 1

cnt = 0
for key in mp1:
    cnt += mp2.get(key, 0) * mp1[key]

print(cnt)
