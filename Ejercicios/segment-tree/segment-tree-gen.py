"""
Segment Tree Implementation
Carlos Ramírez
Noviembre 7 de 2020

General Queries

"""

#Segment tree is represented as a list
n, MAXN = int(), 1000
tree = [None for _ in range(MAXN * 2)]

#build the segment tree
def build(a, v, l, r):
    if l == r: tree[v] = create_value(a[l])
    else:
        m = l + ((r - l) >> 1)
        build(a, v + 1, l, m)
        build(a, v + 2 * (m - l + 1), m + 1, r)
        tree[v] = combine(tree[v + 1], tree[v + 2 * (m - l + 1)])

#query
def query(v, L, R, l, r):
    ans = None
    if l > r: ans = inv_value()
    elif l == L and r == R: ans = tree[v]
    else:
        m = L + ((R - L) >> 1)
        ans = combine(query(v + 1, L, m, l, min(r, m)), query(v + 2 * (m - L + 1), m + 1, R, max(l, m + 1), r))
    return ans

#update query
def update(v, L, R, pos, h):
    if L == R: tree[v] = create_value(h)
    else:
        m = L + ((R - L) >> 1)
        if pos <= m: update(v + 1, L, m, pos, h)
        else: update(v + 2 * (m - L + 1), m + 1, R, pos, h)
        tree[v] = combine(tree[v + 1], tree[v + 2 * (m - L + 1)])

#maximum and number of ocurrences
"""
def combine(p1, p2):
    ans = None
    if p1[0] > p2[0]: ans = p1
    elif p2[0] > p1[0]: ans = p2
    else: ans = (p1[0], p1[1] + p2[1])
    return ans

def create_value(h): return (h, 1)

def inv_value(): return (float('-inf'), 0)
"""

#sum
"""
def combine(p1, p2): return p1 + p2

def create_value(h): return h

def inv_value(): return 0
"""

#max
"""
def combine(p1, p2): return max(p1, p2)

def create_value(h): return h

def inv_value(): return float('-inf')
"""

#gcd
def combine(p1, p2):
    ans = None
    if p1 == -1: ans = p2
    elif p2 == -1: ans = p1
    else: ans = gcd(p1, p2)
    return ans

def create_value(h): return h

def inv_value(): return -1

def gcd(a, b):
    ans = None
    if b == 0: ans = a
    else: ans = gcd(b, a % b)
    return ans

n = 11
build([3, 6, 9, 15, 6, 9, 12, 21, 90, 102, 30], 0, 0, n - 1)
for i in range(2 * n):
    print(str(tree[i]) + " ", end = '')
print()

print(query(0, 0, n - 1, 0, n - 1))
print(query(0, 0, n - 1, 8, 10))
update(0, 0, n - 1, 4, -2)
for i in range(2 * n):
    print(str(tree[i]) + " ", end = '')
print()
