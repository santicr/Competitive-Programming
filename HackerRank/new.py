def main(a, b):
	if a <= 0 and b <= 0:
		return 1
	if a % 2 == 0:
		return a + main(b, b - 1)
	else:
		return b + main(a + 1, b)

print(main(6, 2))