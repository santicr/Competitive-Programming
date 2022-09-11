from sys import stdin
import sys
dic = {0:'fill A', 1:'fill B', 2:'empty A', 3:'empty B', 4:'pour A B', 5:'pour B A'}
solG = []
A, B, C = int(), int(), int()
sys.setrecursionlimit(10**8)

def cond(last, i):
	ans = False
	if last <= 1 and i > 1:
		ans = True
	elif last >= 2 and last <= 3 and (i < 2 or i > 3):
		ans = True
	elif last >= 4 and last <= 5 and i < 4:
		ans = True
	return ans

def bt(a, b, sol, vis):
	global A, B, C, solG
	if (b == C or a == C):
		if len(solG) == 0:
			solG = sol
	elif len(solG) == 0:
		for i in range(6):
			if (len(sol) == 0 or (len(sol) != 0 and cond(sol[-1], i))):
				sc = sol.copy()
				sc.append(i)
				if i == 0 and ((A, b) not in vis or vis[(A, b)] == 0):
					vis[(A, b)] = 1
					bt(A, b, sc, vis)
					vis[(A, b)] = 0
				elif i == 1 and ((a, B) not in vis or vis[(a, B)] == 0):
					vis[(a, B)] = 1
					bt(a, B, sc, vis)
					vis[(a, B)] = 0
				elif i == 2 and ((0, b) not in vis or vis[(0, b)] == 0):
					vis[(0, b)] = 1
					bt(0, b, sc, vis)
					vis[(0, b)] = 0
				elif i == 3 and ((a, 0) not in vis or vis[(a, 0)] == 0):
					vis[(a, 0)] = 1
					bt(a, 0, sc, vis)
					vis[(a, 0)] = 0
				elif i == 4:
					if (b + a) == B and ((0, B) not in vis or vis[(0, B)] == 0):
						vis[(0, B)] = 1
						bt(0, B, sc, vis)
						vis[(0, B)] = 0
					elif (b + a) < B and ((0, b + a) not in vis or vis[(0, b + a)] == 0):
						vis[(0, b + a)] = 1
						bt(0, b + a, sc, vis)
						vis[(0, b + a)] = 0
					elif (b + a) > B and (((b + a) - B, B) not in vis or vis[((b + a) - B, B)] == 0):
						vis[((b + a) - B, B)] = 1
						bt((b + a) - B, B, sc, vis)
						vis[((b + a) - B, B)] = 0
				elif i == 5:
					if (b + a) == A and ((A, 0) not in vis or vis[(A, 0)] == 0):
						vis[(A, 0)] = 1
						bt(A, 0, sc, vis)
						vis[(A, 0)] = 0
					elif (b + a) < A and ((b + a, 0) not in vis or vis[(b + a, 0)] == 0):
						vis[(b + a, 0)] = 1
						bt(b + a, 0, sc, vis)
						vis[(b + a, 0)] = 0
					elif (b + a) > A and ((A, (b + a) - A) not in vis or vis[(A, (b + a) - A)] == 0):
						vis[(A, (b + a) - A)] = 1
						bt(A, (b + a) - A, sc, vis)
						vis[(A, (b + a) - A)] = 0

def solve(a, b, c):
	global A, B, C, solG
	A = a
	B = b
	C = c
	s = bt(0, 0, [], {(0, 0):1})
	return solG

def main():
	global dic, solG
	linea = stdin.readline().strip()
	while(linea != ""):
		linea = linea.split()
		s = (solve(int(linea[0]), int(linea[1]), int(linea[2])))
		for i in range(len(s)):
			print(dic[s[i]])
		print("success")
		linea = stdin.readline().strip()
		solG = []
main()