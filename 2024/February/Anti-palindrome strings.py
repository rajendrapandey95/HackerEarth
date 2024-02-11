def solve():
    s = input()
    s = sorted(s)
    if s[0] == s[-1]:
        print(-1)
    else:
        print("".join(s))

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
