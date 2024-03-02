def main():
    l, r = map(int, input().split())

    if l % 2 == 0:
        l += 1
    if r % 2 == 0:
        r -= 1

    no_of_odd_nos = ((r - l) // 2) + 1

    if no_of_odd_nos % 2:
        print("odd")
    else:
        print("even")

if __name__ == "__main__":
    main()
