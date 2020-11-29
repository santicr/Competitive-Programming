"""
Segment Tree Implementation
Carlos Ramírez
Noviembre 7 de 2020

"""

#Segment tree is represented as a list
n, MAXN = int(), 1000
tree = [0 for _ in range(MAXN * 4)]

#build the segment tree
def build(a, v, l, r):
    if l == r: tree[v] = a[l]
    else:
        m = l + ((r - l) >> 1) # (l + r) // 2
        build(a, 2 * v + 1, l, m)
        build(a, 2 * (v + 1), m + 1, r)
        tree[v] = tree[2 * v + 1] + tree[2 * (v + 1)]

#sum query
def sum(v, L, R, l, r): # sum(0, 0, n - 1, 2, 5)
    ans = None
    if l > r: ans = 0
    elif l == L and r == R: ans = tree[v]
    else:
        m = L + ((R - L) >> 1)
        ans = sum(2 * v + 1, L, m, l, min(r, m)) + sum(2 * (v + 1), m + 1, R, max(l, m + 1), r)
    return ans

build([2, 8, 6, 9, 7, 5, 4, 3, 1], 0, 0, 8)
for i in range(36):
    print(str(tree[i]) + " ", end = '')
print()

print(sum(0, 0, 8, 2, 5))
print(sum(0, 0, 8, 0, 6))
for i in range(36):
    print(str(tree[i]) + " ", end = '')
print()
