MAXN = 10000
MCAL = 100000
MAXL = 1000000000

def main():
    T = int(input())
    assert 0 < T <= 100
    for _ in range(T):
        dish = []

        A, B, N = map(int, input().split())
        assert 0 < N <= MAXN
        assert 0 < A <= MAXL
        assert 0 < B <= MAXL

        for _ in range(N):
            cal = int(input())
            assert 0 < cal <= MCAL
            dish.append(cal)
        dish.sort()
        cntA = cntB = 0

        for cal in dish:
            if A >= cal:
                A -= cal
                cntA += 1
            if B >= cal:
                B -= cal
                cntB += 1
        
        if cntA > cntB:
            print("Raghu Won")
        elif cntA < cntB:
            print("Sayan Won")
        else:
            print("Tie")

if __name__ == "__main__":
    main()
