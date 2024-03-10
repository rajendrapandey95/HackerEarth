import sys
from collections import defaultdict

def main():
    t = int(input().strip())
    for _ in range(t):
        n, k = map(int, input().strip().split())
        nums = list(map(int, input().strip().split()))
        nums.sort()
        freq = defaultdict(int)
        for num in nums:
            freq[num] += 1
        sums = []
        for num, f in freq.items():
            sums.append(num * f)
        sums.sort(reverse=True)
        total = 0
        for i in range(k):
            if i < len(sums):
                if sums[i] <= 0:
                    break
                total += sums[i]
        print(total)

if __name__ == "__main__":
    main()
