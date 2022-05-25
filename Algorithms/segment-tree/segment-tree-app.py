"""
Segment Tree Implementation
Carlos Ramírez
Noviembre 7 de 2020

Counting the number of zeros, searching for the k-th zero

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

#counting number of zeros
def combine(p1, p2):
    return p1 + p2

def create_value(h):
    if h == 0: return 1
    else: return 0

def inv_value(): return 0


#find the k-th zero
def find(v, l, r, k):
    ans = None
    if k > tree[v]: ans = -1
    elif l == r: ans = l
    else:
        m = l + ((r - l) >> 1)
        if tree[v + 1] >= k: ans = find(v + 1, l, m, k)
        else: ans = find(v + 2 * (m - l + 1), m + 1, r, k - tree[v + 1])
    return ans

n = 11
build([3, 0, 9, 10, 0, 4, 0, 0, 9, 0, 3], 0, 0, n - 1)
for i in range(2 * n):
    print(str(tree[i]) + " ", end = '')
print()

print(query(0, 0, n - 1, 0, n - 1))
print(query(0, 0, n - 1, 0, 2))

print(find(0, 0, n - 1, 3))

update(0, 0, n - 1, 0, 0)
for i in range(2 * n):
    print(str(tree[i]) + " ", end = '')
print()

print(find(0, 0, n - 1, 3))
