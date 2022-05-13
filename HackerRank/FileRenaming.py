import sys
#
# Complete the 'renameFile' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. STRING newName
#  2. STRING oldName
#
sys.setrecursionlimit(10**9)
nN = str()
n = int()
m = int()
oN = str()
memo = {}
#i para n, j para m

def solve(i, j):
    ans = None

    if (i, j) in memo:
        ans = memo[(i, j)]
    else:
        if i == n and j == m:
            ans = 1
        elif i == n and j < m:
            ans = 1
        elif i < n and j == m:
            ans = 0
        elif i < n and j < m and nN[i] == oN[j]:
            ans = solve(i, j + 1) + solve(i + 1, j + 1)
        elif i < n and j < m and nN[i] != oN[j]:
            ans = solve(i, j + 1)
        memo[(i, j)] = ans
    return ans
        
    
def renameFile(newName, oldName):
    global nN, n, oN, m
    nN = newName
    oN = oldName
    n = len(newName)
    m = len(oldName)
    
    return solve(0, 0) % (10**9+7)