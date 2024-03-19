def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        if n % 4 == 0:
            print("1", n)
        elif n % 4 == 1:
            print("1", 1)
        elif n % 4 == 2:
            print("2", n, n ^ (n + 1))
        else:
            print("0")

if __name__ == "__main__":
    main()
