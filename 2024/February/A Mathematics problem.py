MAXX = 100005
mod = 1000000007

primes = []
isprime = [False] * MAXX

def sieve():
    global primes, isprime
    for i in range(2, MAXX):
        if isprime[i]:
            continue
        for j in range(i * i, MAXX, i):
            isprime[j] = True
        primes.append(i)

def square(a):
    return a * a

def sum1(n):
    if n == 0:
        return 0
    if n % 2 == 1:  # Odd n
        return square((n + 1) // 2) + sum1(n // 2)
    else:  # Even n
        return square(n // 2) + sum1(n // 2)

def main():
    global mod, primes
    t = int(input())
    sieve()
    for _ in range(t):
        P, Q, N = map(int, input().split())
        ans = 0
        for p in primes:
            if p < P:
                continue
            if p > Q:
                break
            n = N
            while n:
                sum_val = (n * (n + 1) // 2) - 2 * (sum1(n))
                sum_val = (sum_val + mod) % mod
                ans += ((p - 1) * sum_val) % mod
                ans = (ans + mod) % mod
                n //= p
        print(ans)

if __name__ == "__main__":
    main()
