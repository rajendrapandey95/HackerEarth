def solution(N, C):
    ans = []
    stack = []

    for it in C:
        if it == 0:
            ans.append(stack.pop())
        else:
            stack.append(it)

    return ans


if __name__ == "__main__":
    N = int(input())
    assert 1 <= N <= 100000

    C = list(map(int, input().split()))
    for i in range(N):
        assert 0 <= C[i] <= 1e9

    out_ = solution(N, C)

    print(out_[0], end="")
    for i_out_ in range(1, len(out_)):
        print(" " + str(out_[i_out_]), end="")
