from sys import stdin

sols = []
n, h = int(), int()

def solve(sol, tam):
    global sols
    
    if len(sol) == n and tam == 0:
        sols.append(sol)

    elif len(sol) < n and tam >= 0:
        solve(sol + '1', tam - 1)
        solve(sol + '0', tam)

def main():
    global n, h, sols
    cases = int(input())

    for i in range(cases):
        if i != 0:
            print()

        line = stdin.readline()
        n, h = tuple(map(int, stdin.readline().strip().split()))
        sols = []

        solve('', h)
        sols.sort()

        for bit in sols:
            print(bit)

main()