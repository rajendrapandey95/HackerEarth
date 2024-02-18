s = list(input())
opening = []
for i in range(len(s)):
    if s[i] == '/':
        opening.append(i)
    elif s[i] == '\\':
        s[opening[-1]:i + 1] = reversed(s[opening[-1]:i + 1])
        opening.pop()
print(''.join(filter(lambda c: c != '\\' and c != '/', s)))
