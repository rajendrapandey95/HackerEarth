import math

def f(v):
    global g, n
    if v > n:
        return
    if v > 0:
        g.append(v)
    f(10 * v + 4)
    f(10 * v + 7)

if __name__ == "__main__":
    n = int(input())
    g = []
    f(0)
    result = 0
    for i in range(len(g)):
        for j in range(i + 1, len(g)):
            if math.gcd(g[i], g[j]) == 1:
                result += 1
    print(result)
