from sys import stdin

def solve(x):
    total = 0
    if x > 1000000:
        total += ((x - 1000000) * 7)
        x -= (x - 1000000)

    if x > 10000:
        total += ((x - 10000) * 5)
        x -= (x - 10000)

    if x > 100:
        total += ((x - 100) * 3)
        x -= (x - 100)

    if x > 0:
        total += x * 2

    return int(total)

def main():
    linea = stdin.readline()
    linea = linea.split()

    A = int(linea[0])
    B = int(linea[1])

    while(A != 0 and B != 0):
        t1 = False
        t2 = False
        t3 = False

        total = 0
        n = 0
        
        if(A > 200):
            total += 200
            n += 100
            t1 = True

        if(A > 29900):
            total += 29700
            n += 9900
            t2 = True

        if(A > 4979900):
            total += 4950000
            n += 990000
            t3 = True

        if(t3 == True):
            n += (A - total) // 7;
        
        elif(t2 == True):
            n += (A - total) // 5;
        
        elif(t1 == True):
            n += (A - total) // 3;   
        
        else:
            n += (A // 2);

        m = n
        low = 0
        high = n // 2
        s1 = -1
        s2 = -3

        while(low + 1 < high and abs(s1 - s2) != B):
            mid = (low + high) // 2
            s1 = mid
            s2 = m - s1
            s1 = solve(s1)
            s2 = solve(s2)

            if(abs(s1 - s2) > B):
                low = mid
            else:
                high = mid

        s1 = high
        s1 = solve(s1)

        print(s1)
        s1 = -1
        s2 = -1

        linea = stdin.readline()
        linea = linea.split()

        A = int(linea[0])
        B = int(linea[1])

main()