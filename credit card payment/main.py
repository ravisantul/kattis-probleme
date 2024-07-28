import sys; input = sys.stdin.readline

for _ in range(int(input())):
    r, a, m = map(lambda x: round(float(x)*100), input().split())
    r = 1 + r/10000
    for i in range(1, 1201):
        a = a * r - m
        a = int(a) + (a - int(a) >= 0.5 - 1e-8)
        if a <= 0:
            break
    if a > 0:
        print('impossible')
    else:
        print(i)
