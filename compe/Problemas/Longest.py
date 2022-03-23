from sys import stdin

def solve(X, Y, m, n):
    LCSuff = [[0 for k in range(n+1)] for l in range(m+1)]
    result = 0
    for i in range(m + 1):
        for j in range(n + 1):
            if (i == 0 or j == 0):
                LCSuff[i][j] = 0
            elif (X[i-1] == Y[j-1]):
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1
                result = max(result, LCSuff[i][j])
            else:
                LCSuff[i][j] = 0
    return result
 
n = int(input())
menor = float("inf")
strm = ""
cads = []

for i in range(n):
    cad = stdin.readline().strip()
    cads.append(cad)
    if(len(cad) < menor):
        menor = len(cad)
        strm = cad

minV = float("inf")
for i in range(n):
    if(cads[i] != strm):
        tam = solve(cads[i], strm, len(cads[i]), len(strm))
        if(minV > tam):
            minV = tam
print(minV)