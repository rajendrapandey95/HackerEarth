from collections import deque

N = int(input())
Q = deque(map(int, input().split()))

a = list(map(int, input().split()))

total_time = 0
executed_job = 0

while Q:
    job = Q.popleft()

    if job == a[executed_job]:
        total_time += 1
        executed_job += 1
    else:
        Q.append(job)
        total_time += 1

print(total_time)
