def main():
    """
    Main function to execute the logic for comparing arrays a and b after specific operations.

    Input:
    - t (int): Number of test cases.
    - For each test case:
        - n (int): Size of the arrays a and b.
        - a (list[int]): Elements of array a.
        - b (list[int]): Elements of array b.

    Output:
    - Prints 'Yes' or 'No' for each test case based on whether arrays a and b are identical after specific operations.

    Algorithm:
    1. Iterate through each test case.
    2. Read the size of the arrays (n) and their elements (a and b).
    3. Perform cumulative sum on both arrays a and b.
    4. Check if the last elements of a and b are equal.
    5. If not equal, print 'No'.
    6. If equal, sort both arrays a and b.
    7. Check if arrays a and b are identical.
    8. If identical, print 'Yes', otherwise print 'No'.

    Example:
    ```
    Input:
    2
    3
    1 2 3
    1 2 3
    4
    1 2 3 4
    4 3 2 1

    Output:
    Yes
    No
    ```

    Time Complexity:
    - The time complexity depends on the size of the input arrays and sorting, resulting in O(n log n) for each test case.

    Space Complexity:
    - The space complexity is O(n) for storing the input arrays.
    """

    t = int(input())  # Number of test cases
    for _ in range(t):
        n = int(input())  # Size of the arrays
        a = list(map(int, input().split()))  # Elements of array a
        b = list(map(int, input().split()))  # Elements of array b

        # Cumulative sum for both arrays
        for i in range(1, n):
            a[i] += a[i-1]
            b[i] += b[i-1]

        if a[-1] != b[-1]:
            print("No")
        else:
            a.sort()
            b.sort()
            if a == b:
                print("Yes")
            else:
                print("No")

if __name__ == "__main__":
    main()
