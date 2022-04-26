import math

def dist(p1, p2):
	ans = (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2
	return math.sqrt(ans)

def solution(dim, posA, posB, shotDis):
	#(0, 0) (dim[0], dim[1]) (0, dim[1]) (dim[0], 0)
	x = posA[0]
	y = posA[1]
	xE = posB[0]
	yE = posB[1]
	print(dim[1], y)
	#Hipotenusas d1, d2, d3, d4
	d1, d2 = dist(posA, (0, 0)), dist(posA, dim)
	d3, d4 = dist(posA, (0, dim[1])), dist(posA, (dim[0], 0))
	puntos = [(x, y), (dim[0] - x, dim[1] - y), (x, dim[1] - y), (dim[0] - x, y)] #CA y CO
	a1, a2 = math.asin(y/d1)*180/math.pi, math.asin((dim[1] - y)/d2)*180/math.pi
	a3, a4 = math.asin((x) / d3)*180/math.pi, math.asin((dim[0] - x)/d4)*180/math.pi
	angulos = [a1 + 180, a2, a3 + 90, a4 + 270]#Angulos
	print(angulos)

	for i in range(360):
		if(i >= 1 and i < angulos[1]):
			ca = dim[0] - x
			co = ca * math.tan(i)
			y2 = co + y
			x2 = ca + x
			m = (y2 - y) / (x2 - x)
			ym = m*(xE - x) + y

		elif(i > d2 and i < d3):
			pass
		elif(i > d3 and i < d1):
			pass
		elif(i > d4):
			pass


def main():
	(solution([3, 2], [1, 1], [2, 1], 3))

main()