def count_set_bits(num):
    count = 0
    while num:
        count += num & 1
        num >>= 1
    return count

def solve(arr):
    ans = []
    odd_set_bits = []
    for num in arr:
        if count_set_bits(num) % 2 == 0:
            ans.append(num)
        else:
            odd_set_bits.append(num)

    ans.sort()
    odd_set_bits.sort()

    for x in odd_set_bits:
        ans.append(x)

    return ans

def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(A)
        for num in result:
            print(num, end=" ")
        print()

if __name__ == "__main__":
    main()
