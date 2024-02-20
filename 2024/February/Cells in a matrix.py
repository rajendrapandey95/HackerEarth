def main():
    n, m = map(int, input().split())
    row = set()
    col = set()
    for i in range(m):
        l, r = map(int, input().split())
        row.add(l)
        col.add(r)
        print((n - len(row)) * (n - len(col)), end=" ")

if __name__ == "__main__":
    main()
