def solve(N, workload):
    max_consecutive_days = 0
    current_consecutive_days = 0
 
    for hours in workload:
        if hours > 6:
            current_consecutive_days += 1
        else:
            max_consecutive_days = max(max_consecutive_days, current_consecutive_days)
            current_consecutive_days = 0
 
    
    max_consecutive_days = max(max_consecutive_days, current_consecutive_days)
 
    return max_consecutive_days
 
if __name__ == "__main__":
    N = int(input())
    workload = list(map(int, input().split()))
 
    rating = solve(N, workload)
    print(rating)
