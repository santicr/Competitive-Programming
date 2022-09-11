from sys import stdin

t1, t2 = int(), int()
memo = {}

def solve(n):
    ans = None
    if n in memo:
        ans = memo[n]
    else:
        if n == 1:
            ans = t1
        elif n == 2:
            ans = t2
        else:
            ans = solve(n - 2) + solve(n - 1) ** 2
        memo[n] = ans
    return ans

def main():
    global t1, t2
    l = stdin.readline().split()
    t1, t2, n = int(l[0]), int(l[1]), int(l[2])

    print(solve(n))

main()