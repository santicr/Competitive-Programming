"""
Segment Tree Implementation
Carlos Ramírez
Noviembre 7 de 2020

Update with lazy propagation
Adding on segments, range max query (RMQ)

"""

#Segment tree is represented as a list
n, MAXN = int(), 1000
tree = [None for _ in range(MAXN * 2)]
pend = [0 for _ in range(MAXN * 2)]

#build the segment tree
def build(a, v, l, r):
    if l == r: tree[v] = cond(a[l])
    else:
        m = l + ((r - l) >> 1)
        build(a, v + 1, l, m)
        build(a, v + 2 * (m - l + 1), m + 1, r)
        tree[v] = (tree[v + 1] + tree[v + 2 * (m - l + 1)])
        
#query
def query(v, L, R, l, r):
    ans = None
    if l > r: ans = float('-inf')
    elif l <= L and r <= R: ans = tree[v]
    else:
        m = L + ((R - L) >> 1)
        push(v, v + 1, v + 2 * (m - L + 1))
        ans = max(query(v + 1, L, m, l, min(r, m)), query(v + 2 * (m - L+ 1), m + 1, R, max(l, m + 1), r))
    return ans

#query
def query_zero(v, L, R, l, r):
    ans = None
    if l > r: ans = 0
    elif l <= L and r <= R: ans = tree[v]
    else:
        m = L + ((R - L) >> 1)
        push(v, v + 1, v + 2 * (m - L + 1))
        ans = (query_zero(v + 1, L, m, l, min(r, m)) + query_zero(v + 2 * (m - L+ 1), m + 1, R, max(l, m + 1), r))
    return ans

#update query
def update(v, L, R, l, r, h):
    if l <= r:
        if l == L and r == R: tree[v] += h ; pend[v] += h
        else:
            m = L + ((R - L) >> 1)
            push(v, v + 1, v + 2 * (m - L + 1))
            update(v + 1, L, m, l, min(r, m), h)
            update(v + 2 * (m - L + 1), m + 1, R, max(l, m + 1), r, h)
            tree[v] = (tree[v + 1] + tree[v + 2 * (m - L + 1)])

def push(v, v1, v2):
    tree[v1] += pend[v]
    pend[v1] += pend[v]
    tree[v2] += pend[v]
    pend[v2] += pend[v]
    pend[v] += 0

def cond(v):
    if(v == 1):
        return 1
    else:
        return 0

n = 5
a = [1, 1, 1, 1, 1]
build(a, 0, 0, n - 1)
for i in range(2 * n):
    print(str(tree[i]) + " ", end = '')
print()
print(query(0, 0, n - 1, 0, 4))
update(0, 0, n - 1, 0, 4, 1)
for i in range(2 * n):
    print(str(tree[i]) + " ", end = '')
print()
print(query(0, 0, n - 1, 2, 2))

"""
casos = int(input())
i = 0

while(i < casos):
    m = int(input())
    cad = str()
    j = 0

    while(j < m):
        rep = int(input())
        linea = str(input())
        k = 0
        
        while(k < rep):
            cad += linea
            k += 1

        j += 1

    size = len(cad) - 1
    lista = []
    consultas = int(input())
    j = 0
    while(j <= size):
        lista.append(int(cad[j]))
        j += 1
    build(lista, 0, 0, size)
    j = 0

    while(j < consultas):
        linea = stdin.readline()
        linea = linea.split()
        if(linea[0] == 'F'):
            update(0, 0, size, int(linea[1]) - 1, int(linea[2]) - 1, 1)
        print(query(0, 0, size, 0, 2))
        j += 1

    i += 1 """