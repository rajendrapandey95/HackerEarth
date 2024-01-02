def solve(x: int, l: int, n: int) -> None:
    """
    Solve a specific problem with given parameters.

    Parameters:
    - x (int): The initial value of x.
    - l (int): The limit value.
    - n (int): The number of iterations.

    Returns:
    - None

    This function prints the maximum number of erasures allowed while satisfying certain conditions.
    """

    min_erased = -1
    max_erased = x

    while max_erased - min_erased > 1:
        erased = (min_erased + max_erased) // 2

        cur_x = x - erased
        good = True

        for _ in range(n):
            if cur_x > l:
                good = False
                break
            cur_x *= 2

        if good:
            max_erased = erased
        else:
            min_erased = erased

    print(max_erased)


def main() -> None:
    """
    Main function to execute the solve function based on user input.

    Parameters:
    - None

    Returns:
    - None

    This function takes user input, specifies the number of test cases, and calls the solve function for each test case.
    """

    t = int(input("Enter the number of test cases: "))
    for _ in range(t):
        x, l, n = map(int, input().split())
        solve(x, l, n)


if __name__ == "__main__":
    main()
