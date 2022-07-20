from sys import stdin

def solve(grades):
    res = []
    for x in grades:
        nv = int()
        if x % 5 != 0:
            nv = int(x / 5) + 1
        else:
            nv = int(x / 5)

        if nv * 5 - x < 3 and nv * 5 >= 38:
            res.append(nv * 5)
        else:
            res.append(x)
    
    return res

def main():
    grades = []
    n = int(input())

    for i in range(n):
        nv = int(input())
        grades.append(nv)
    
    ans = solve(grades)

    for x in ans:
        print(x)

main()