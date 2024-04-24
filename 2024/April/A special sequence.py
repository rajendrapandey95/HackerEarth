from bisect import bisect_left
from math import sqrt
import sys


input = sys.stdin.readline

a = [2]
while a[-1] < 1e13:
    i = len(a) + 1
    a.append(a[-1] + i * int(sqrt(i)) + (i + 1) // 2)

q = int(input())
for _ in range(q):
    l, r = map(int, input().split())
    print(bisect_left(a, r) - bisect_left(a, l) + 1)
