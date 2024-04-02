MOD = 1000000007

def main():
    t = int(input())
    assert 1 <= t <= 100000
    
    for _ in range(t):
        n = int(input())
        assert 3 <= n <= 1000000000
        assert n % 2 == 1
        
        n -= 1
        tmp = n // 2
        
        mn = (tmp * tmp) % MOD
        mn = (mn * (n + 1)) % MOD
        
        mx = (n * (n + 1)) % MOD
        mx = (mx * (2 * n + 1)) % MOD
        mx = (mx * 166666668) % MOD
        
        print(mn, mx)

if __name__ == "__main__":
    main()
