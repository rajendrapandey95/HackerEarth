import math

def main():
    test = int(input())

    while test > 0:
        a, b, n = map(int, input().split())

        if n % 3 == 1:
            print(a)
        elif n % 3 == 2:
            print(b)
        else:
            xor_ = a ^ b
            bits = int(math.log2(max(a, b))) + 1
            all_ones = (1 << bits) - 1
            xnor_ = all_ones ^ xor_
            print(max(xor_, xnor_))

        test -= 1

if __name__ == "__main__":
    main()
