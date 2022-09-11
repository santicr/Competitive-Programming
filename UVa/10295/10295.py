from sys import stdin

def main():
	n, m = map(int, stdin.readline().split())
	dic = {}

	for i in range(n):
		l = stdin.readline().split()
		k = l[0]
		v = int(l[1])
		dic[k] = v

	for i in range(m):
		ans = 0
		l = stdin.readline().strip()
		while l != '.':
			l = l.split()
			for w in l:
				if w in dic:
					ans += dic[w]
			l = stdin.readline().strip()
		print(ans)
main()