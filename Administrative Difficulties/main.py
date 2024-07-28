import sys; input = sys.stdin.readline
for _ in range(int(input())):
    n, m = map(int, input().split())
    P = {}; R = {}; RA = {}; F = {}; C = {}; CO = {}
    for _ in range(n): N, *r = input().split(); P[N], R[N], RA[N] = map(int, r)
    for _ in range(m):
        _, p, e, r = input().split()
        if p not in CO: F[p], C[p], CO[p] = None, True, 0
        if e == 'p':
            if F[p] != None: C[p] = False
            if C[p]: c = r.strip(); CO[p] += R[c]; F[p] = c
        elif e == 'r':
            if F[p] == None: C[p] = False
            if C[p]: CO[p] += int(r)*RA[F[p]]; F[p] = None
        else:
            if F[p] == None: C[p] = False
            if C[p]: CO[p] += (int(r)*P[F[p]]+99)//100
    for p in F:
        if F[p] != None: C[p] = False
    for p in sorted(CO): print(p, cost[p] if C[p] else 'INCONSISTENT')