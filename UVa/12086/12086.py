from sys import stdin

#Segment tree is represented as a list
n, MAXN = int(), 200002
tree = [0 for _ in range(MAXN * 2)]

#build the segment tree
def build(a, v, l, r):
    if l == r: tree[v] = a[l]
    else:
        m = l + ((r - l) >> 1)
        build(a, v + 1, l, m)
        build(a, v + 2 * (m - l + 1), m + 1, r)
        tree[v] = tree[v + 1] + tree[v + 2 * (m - l + 1)]

#sum query
def sum(v, L, R, l, r):
    ans = None
    if l > r: ans = 0
    elif l == L and r == R: ans = tree[v]
    else:
        m = L + ((R - L) >> 1)
        ans = sum(v + 1, L, m, l, min(r, m)) + sum(v + 2 * (m - L + 1), m + 1, R, max(l, m + 1), r)
    return ans

#update query
def update(v, L, R, pos, h):
    if L == R: tree[v] = h
    else:
        m = L + ((R - L) >> 1)
        if pos <= m: update(v + 1, L, m, pos, h)
        else: update(v + 2 * (m - L + 1), m + 1, R, pos, h)
        tree[v] = tree[v + 1] + tree[v + 2 * (m - L + 1)]

n = int(input())
caso = 1

while(n != 0):
    pot = []
    i = 0

    while(i < n):
        resistencia = int(input())
        pot.append(int(resistencia))
        i += 1

    if(caso > 1) : print()
    casos = "Case {}:".format(caso)
    print(casos)
    build(pot, 0, 0, n - 1)
    linea = stdin.readline()
    linea = linea.split()
    
    while(linea[0] != "END"):
        if(linea[0] == "M"):
            print(sum(0, 0, n - 1, int(linea[1]) - 1, int(linea[2]) - 1))
        else:
            update(0, 0, n - 1, int(linea[1]) - 1, int(linea[2]))
        linea = stdin.readline()
        linea = linea.split()
    
    n = int(input())
    caso += 1