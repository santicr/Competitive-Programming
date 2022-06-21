from sys import stdin

def main():
	l = stdin.readline().strip()
	while l != "":
		print(l)
		l = stdin.readline().strip()

main()