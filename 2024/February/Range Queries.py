a = [[0] * 20 for _ in range(100005)]

def pre_process():
    for i in range(1, 100001):
        val = 1
        for j in range(1, 20):
            if val <= i:
                if i & val:
                    a[i][j] = 1
                val *= 2

    for i in range(1, 20):
        for j in range(1, 100001):
            a[j][i] += a[j - 1][i]

def main():
    pre_process()
    q = int(input())
    for _ in range(q):
        l, r, x = map(int, input().split())
        answer = a[r][x] - a[l - 1][x]
        print(answer)

if __name__ == "__main__":
    main()
