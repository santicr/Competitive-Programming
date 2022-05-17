from sys import stdin

def solve(grid):
	tams = []
	for i in range(len(grid)):
		tams.append(len(grid[i]))
	

def main():
	grid = []
	
	for i in range(10):
		linea = stdin.readline().strip()
		grid.append(linea)

	print(solve(grid))

main()