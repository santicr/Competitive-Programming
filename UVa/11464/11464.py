from sys import stdin

res = float("inf")

def parity():
    pass

def solve(sol, moves):
    global res
    n = len(sol)
    temp = [[0 for _ in range(n)] for _ in range(n)]
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    if moves < res and parity():
        res = moves

    elif moves < res:
        for i in range(n):
            for j in range(n):
                if not sol[i][j]:
                    sol[i][j] = 1
                    solve(sol, moves + 1)
                    sol[i][j] = 0

def main():
    global res
    cases = int(input())

    for i in range(cases):
        mat = []
        n = int(input())
        res = float("inf")

        for j in range(n):
            row = list(map(int, stdin.readline().strip().split()))
            mat.append(row)

        solve(mat, 0)

        if res == float("inf"):
            print(f"Case {str(i + 1)}: {str(-1)}")
        else:
            print(f"Case {str(i + 1)}: {str(res)}")

main()