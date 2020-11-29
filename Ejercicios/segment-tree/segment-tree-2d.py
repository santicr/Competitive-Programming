"""
Segment Tree Implementation
Carlos Ramírez
Noviembre 7 de 2020

"""

#Segment tree is represented as a list
n, c, MAXN = int(), int(), 1000
tree = [[0 for _ in range(MAXN * 4)] for _ in range(MAXN * 4)]

#build the segment tree
def buildX(a, v, l, r):
    if l != r:
        m = l + ((r - l) >> 1) # (l + r) // 2
        buildX(a, 2 * v + 1, l, m)
        buildX(a, 2 * (v + 1), m + 1, r)
    buildY(a, v, l, r, 0, 0, c - 1)

def buildY(a, vx, lx, rx, vy, ly, ry):
    if ly == ry:
        if lx == rx: tree[vx][vy] = a[lx][ly]
        else: tree[vx][vy] = tree[2 * vx + 1][vy] + tree[2 * (vx + 1)][vy]
    else:
        m = ly + ((ry - ly) >> 1)
        buildY(a, vx, lx, rx, 2 * vy + 1, ly, m)
        buildY(a, vx, lx, rx, 2 * (vy + 1), m + 1, ry)
        tree[vx][vy] = tree[vx][2 * vy + 1] + tree[vx][2 * (vy + 1)]

#sum query
def sumY(vx, vy, LY, RY, ly, ry): # sum(0, 0, n - 1, 2, 5)
    ans = None
    if ly > ry: ans = 0
    elif ly == LY and ry == RY: ans = tree[vx][vy]
    else:
        m = LY + ((RY - LY) >> 1)
        ans = sumY(vx, 2 * vy + 1, LY, m, ly, min(ry, m)) + sumY(vx, 2 * (vy + 1), m + 1, RY, max(ly, m + 1), ry)
    return ans

def sumX(vx, LX, RX, lx, rx, ly, ry):
    ans = None
    if lx > rx: ans = 0
    elif lx == LX and rx == RX: ans = sumY(vx, 0, 0, c - 1, ly, ry)
    else:
        m = LX + ((RX - LX) >> 1)
        ans = sumX(2 * vx + 1, LX, m, lx, min(rx, m), ly, ry) + sumX(2 * (vx + 1), m + 1, RX, max(lx, m + 1), rx, ly, ry)
    return ans

#update query
def updateY(vx, LX, RX, vy, LY, RY, x, y, h):
    if LY == RY:
        if LX == RX: tree[vx][vy] = h
        else: tree[vx][vy] = tree[2 * vx + 1][vy] + tree[2 * (vx + 1)][vy]
    else:
        m = LY + ((RY - LY) >> 1)
        if y <= m: updateY(vx, LX, RX, 2 * vy + 1, LY, m, x, y, h)
        else: updateY(vx, LX, RX, 2 * (vy + 1), m + 1, RY, x, y, h)
        tree[vx][vy] = tree[vx][2 * vy + 1] + tree[vx][2 * (vy + 1)]

def updateX(vx, LX, RX, x, y, h):
    if LX != RX:
        m = LX + ((RX - LX) >> 1)
        if x <= m: updateX(2 * vx + 1, LX, m, x, y, h)
        else: updateX(2 * (vx + 1), m +1, RX, x, y, h)
    updateY(vx, LX, RX, 0, 0, c - 1, x, y, h)

a = [[2, 5, 6, 8, 9], [1, 2, 8, 7, 3], [2, 0, -1, 6, 4], [1, 2, 9, 3, 1]]
n = len(a)
c = len(a[0])

buildX(a, 0, 0, n - 1)
for i in range(16):
    for j in range(20):
        print(str(tree[i][j]) + " ", end = '')
    print()

print(sumX(0, 0, n - 1, 1, 2, 2, 4))
print(sumX(0, 0, n - 1, 0, 2, 2, 3))
updateX(0, 0, n - 1, 0, 1, 1)
print(sumX(0, 0, n - 1, 0, 2, 2, 3))

for i in range(16):
    for j in range(20):
        print(str(tree[i][j]) + " ", end = '')
    print()
