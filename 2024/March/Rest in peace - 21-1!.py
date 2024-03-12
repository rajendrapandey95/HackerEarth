tc = int(input())
while tc > 0:
    tc -= 1
    n = int(input())
    m = str(n)
    if '21' in m or n % 21 == 0:
        print("The streak is broken!")
    else:
        print("The streak lives still in our heart!")
