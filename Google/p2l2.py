def solution(x, y):
	x -= 1
	y -= 1
	alt = [1]
	ancho = [1]
	it1 = 1
	it2 = 2
	it3 = 2

	for i in range(1, 100000):
		alt.append(alt[i - 1] + it1)
		ancho.append(ancho[i - 1] + it2)
		it1 += 1
		it2 += 2

	ans = alt[y]

	for i in range(x):
		ans += (y + it3)
		it3 += 1

	return str(ans)


def main():
	x = 10
	y = 3
	print(solution(x, y))

main()