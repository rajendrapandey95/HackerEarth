import sys

def main():
    t = int(input().strip())
    for _ in range(t):
        n = int(input().strip())
        a = list(map(int, input().strip().split()))
        a.sort()
        if n <= 3:
            print(a[n - 1] - a[0])
        else:
            print(a[n - 1] - a[0] + a[n - 2] - a[1])

if __name__ == "__main__":
    main()
