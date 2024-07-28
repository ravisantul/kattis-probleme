n, DE = list(map(int, input().split()))
VAL = list(map(int, input().split()))
TEMP = [-float('inf')] * n

membership = VAL[0] - DE
for i in range(n):
    temperature = VAL[i] - DE * (i + 1)
    membership = min(membership, temperature)
    TEMP[i] = max(TEMP[i], temperature - membership)

membership = -VAL[0] - DE
for i in range(n):
    temperature = -VAL[i] - DE * (i + 1)
    membership = min(membership, temperature)
    TEMP[i] = max(TEMP[i], temperature - membership)

print(*TEMP)
