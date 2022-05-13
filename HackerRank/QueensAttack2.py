import sys
ans = 0

sys.setrecursionlimit(10**7)

def move(rq, cq, i, j, obs, n):
    global ans
    for l in range(n):
        x = rq + i
        y = cq + j
        if x > n and y > n:
            break
        if x >= 1 and x <= n and y >= 1 and y <= n and obs[x][y] == 0:
            rq = x
            cq = y
            ans += 1

def queensAttack(n, k, r_q, c_q, obstacles):
    global ans
    obs = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
    for i in range(k):
        obs[obstacles[i][0]][obstacles[i][1]] = 1
    dx = [0, 0, 1, -1, 1, 1, -1, -1]
    dy = [1, -1, 0, 0, 1, -1, 1, -1]
    
    
    for i in range(8):
        move(r_q, c_q, dx[i], dy[i], obs, n)
    
    return ans

print(queensAttack(100000, 0, 4187, 6068, []))