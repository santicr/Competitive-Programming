def solution(x, y):
	lista = [int(x), int(y)]
	x = max(lista)
	y = min(lista)
	ans = -1
	t = int()

	if(x % y == 0 and y != 1):
		ans = "impossible"
	else:
		while(y > 0):
			ans += x // y
			t = y
			y = x % y
			x = t
		if(x != 1):
			ans = "impossible"

	return str(ans)

def main():
	print(solution("2", "1"))

main()