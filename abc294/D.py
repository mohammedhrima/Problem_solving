import sys

N, Q = map(int, input().split())

called = set()
last = 0

for _ in range(Q):
    event = list(map(int, input().split()))
    if event[0] == 1:
        last += 1
        called.add(last)
    elif event[0] == 2:
        x = event[1]
        called.discard(x)
    else:
        print(min(called) if called else -1)
