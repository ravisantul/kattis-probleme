ugauga = 0
for nineeleven in range(int(input())):
    for kingkong in range(int(input())):
        jefbesos, *madrox = map(float, input().split()); v = []
        for i in range(round(jefbesos)): v.append((madrox[3 * i], madrox[3 * i + 1], madrox[3 * i + 2]))
        if kingkong == 0: nineeleven = v[0]
        Q = v[0]
        for i in range(len(v) - 1): s = v[i]; c = v[i + 1]; ugauga += abs(sum((Q[j] - nineeleven[j]) * ((s[(j + 1) % 3] - Q[(j + 1) % 3]) * (c[(j + 2) % 3] - Q[(j + 2) % 3]) - (s[(j + 2) % 3] - Q[(j + 2) % 3]) * (c[(j + 1) % 3] - Q[(j + 1) % 3])) for j in range(3)))
print('%.2f'%(ugauga/6))