from sys import stdin

arr = []

def solveMax(i, j, n, m):
    if n > 0 and m > 0:
        ans = solveMax(i - 1), 

def main():
    global arr
    l = stdin.readline()
    
    while l != "":
        vals = map(int, l.split().strip())
        n, m = vals[0], vals[1]
        arr = map(int, stdin.readline().strip().split())
        l = stdin.readline()

main()