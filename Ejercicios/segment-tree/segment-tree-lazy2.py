"""
Segment Tree Implementation
Carlos Ramírez
Noviembre 7 de 2020

Update with lazy propagation
Assignment on segments

"""

#Segment tree is represented as a list
n, MAXN = int(), 1000
tree = [None for _ in range(MAXN * 2)]
marked = [False for _ in range(MAXN * 2)]

#build the segment tree
def build(a, v, l, r):
    if l == r: tree[v] = a[l]
    else:
        m = l + ((r - l) >> 1)
        build(a, v + 1, l, m)
        build(a, v + 2 * (m - l + 1), m + 1, r)
        tree[v] = 0
        
#query
def query_pos(v, l, r, pos):
    ans = None
    if l == r: ans = tree[v]
    else:
        m = l + ((r - l) >> 1)
        push(v, v + 1, v + 2 * (m - l + 1))
        if pos <= m:
            ans = query_pos(v + 1, l, m, pos)
        else:
            ans = query_pos(v + 2 * (m - l + 1), m + 1, r, pos)
    return ans

#update query
def update(v, L, R, l, r, h):
    if l <= r:
        if l == L and r == R: tree[v] = h ; marked[v] = True
        else:
            m = L + ((R - L) >> 1)
            push(v, v + 1, v + 2 * (m - L + 1))
            update(v + 1, L, m, l, min(r, m), h)
            update(v + 2 * (m - L + 1), m + 1, R, max(l, m + 1), r, h)

def push(v, v1, v2):
    if marked[v]:
        tree[v1] = tree[v2] = tree[v]
        marked[v1] = marked[v2] = True
        marked[v] = False
            
n = 9
build([3, 2, 5, 7, 4, 6, 2, 5, 4], 0, 0, n - 1)
for i in range(2 * n):
    print(str(tree[i]) + " ", end = '')
print()

print(query_pos(0, 0, n - 1, 6))
print(query_pos(0, 0, n - 1, 8))
update(0, 0, n - 1, 0, 5, 9)
for i in range(2 * n):
    print(str(tree[i]) + " ", end = '')
print()
print(query_pos(0, 0, n - 1, 4))
print(query_pos(0, 0, n - 1, 1))
for i in range(2 * n):
    print(str(tree[i]) + " ", end = '')
print()
