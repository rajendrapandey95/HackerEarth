def removeKdigits(num: str, k: int) -> str:
    stack = []
    i = 0

    if len(num) == k:
        return "0"

    while i < len(num):
        if not stack:
            stack.append(num[i])
            i += 1
            continue

        while stack and k > 0:
            if stack[-1] < num[i]:
                stack.pop()
                k -= 1
            else:
                break

        stack.append(num[i])
        i += 1

    while k > 0:
        stack.pop()
        k -= 1

    result = ""
    while stack:
        result += stack.pop()

    result = result[::-1]

    while result and result[0] == '0':
        result = result[1:]

    if not result:
        return "0"

    return result


if __name__ == "__main__":
    s = input()
    d = len(s)
    assert 1 <= d <= 1000000

    k = int(input())
    assert 0 <= k < d

    print(removeKdigits(s, k))
