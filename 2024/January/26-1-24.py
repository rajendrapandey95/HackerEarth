t = int(input())

for _ in range(t):
    n = int(input())
    s = input()

    m = {}
    for x in s:
        m[x] = m.get(x, 0) + 1

    o = 0
    for x in m.values():
        if x % 2 != 0:
            o += 1

    print(max(0, o - 1))
