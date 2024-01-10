def moji(h, m):
    p = m // 5
    ans = h

    if h >= 12:
        h -= 12
        ans -= 1

    if p > h:
        ans += 1
    elif p == h:
        if m % 5 >= m / 12.0:
            ans += 1

    return ans

def ali(h, m):
    ans = h

    if h >= 12:
        h -= 12
        ans -= 1

    return ans + (11 * m >= h * 60)

if __name__ == "__main__":
    hour, minute = map(int, input().split(':'))
    print(moji(hour, minute))
