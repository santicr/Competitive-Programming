from sys import stdin

def solve(n):
	ans = 0
	if len(n) > 1:
		for i in range(len(n)):
			ans += int(n[i])
		solve(str(ans))
	elif len(n) == 1:
		print(n)


def main():
	l = stdin.readline().strip().split()
	n, k = l[0], int(l[1])
	ans = 0
	p = str()

	for i in range(len(n)):
		ans += int(n[i])

	solve(str(ans * k))

main()