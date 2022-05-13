"""
Segment Tree Implementation
Carlos Ramírez
Noviembre 7 de 2020

Maximum query

"""

#Segment tree is represented as a list
n, MAXN = int(), 1000
tree = [None for _ in range(MAXN * 2)]

#build the segment tree
def build(a, v, l, r):
    if l == r: tree[v] = (a[l], 1)
    else:
        m = l + ((r - l) >> 1)
        build(a, v + 1, l, m)
        build(a, v + 2 * (m - l + 1), m + 1, r)
        tree[v] = combine(tree[v + 1], tree[v + 2 * (m - l + 1)])

#maximum query
def get_max(v, L, R, l, r):
    ans = None
    if l > r: ans = (float('-inf'), 0)
    elif l == L and r == R: ans = tree[v]
    else:
        m = L + ((R - L) >> 1)
        ans = combine(get_max(v + 1, L, m, l, min(r, m)), get_max(v + 2 * (m - L + 1), m + 1, R, max(l, m + 1), r))
    return ans

#update query
def update(v, L, R, pos, h):
    if L == R: tree[v] = (h, 1)
    else:
        m = L + ((R - L) >> 1)
        if pos <= m: update(v + 1, L, m, pos, h)
        else: update(v + 2 * (m - L + 1), m + 1, R, pos, h)
        tree[v] = combine(tree[v + 1], tree[v + 2 * (m - L + 1)])

def combine(p1, p2):
    ans = None
    if p1[0] > p2[0]: ans = p1
    elif p2[0] > p1[0]: ans = p2
    else: ans = (p1[0], p1[1] + p2[1])
    return ans

n = 11
build([3, 6, 9, 10, -5, 4, 2, 7, 9, 10, 3], 0, 0, n - 1)
for i in range(2 * n):
    print(str(tree[i]) + " ", end = '')
print()

print(get_max(0, 0, n - 1, 0, n - 1))
print(get_max(0, 0, n - 1, 3, 6))
update(0, 0, n - 1, 4, -2)
for i in range(2 * n):
    print(str(tree[i]) + " ", end = '')
print()
