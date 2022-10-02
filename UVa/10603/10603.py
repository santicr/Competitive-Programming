from sys import stdin

def bfs(start, obj):
	a, b, c = start
	q = [(0, 0, c)]
	vis = {q[0]: 0}
	ans = (float("inf"), 0)
	res = 0
	flag = False
	vis_ans = float("inf")

	while len(q) != 0:
		u = q.pop(0)
		u1, u2, u3 = u
		if u1 == obj or u2 == obj or u3 == obj:
			if obj > ans[1]:
				ans = vis[u], obj
			ans = min(vis[u], ans[0]), obj
			flag = True
		if not flag:
			if abs(res - obj) > abs(u1 - obj) and u1 < obj:
				res = u1
				ans = vis[u], res
				vis_ans = vis[u]
			if abs(res - obj) > abs(u2 - obj) and u2 < obj:
				res = u2
				ans = vis[u], res
				vis_ans = vis[u]
			if abs(res - obj) > abs(u3 - obj) and u3 < obj:
				res = u3
				ans = vis[u], res
				vis_ans = vis[u]
			if abs(res - obj) == abs(u1 - obj) and u1 < obj and vis[u] < vis_ans:
				res = u1
				ans = vis[u], res
				vis_ans = vis[u]
			if abs(res - obj) == abs(u2 - obj) and u2 < obj and vis[u] < vis_ans:
				res = u2
				ans = vis[u], res
				vis_ans = vis[u]
			if abs(res - obj) == abs(u3 - obj) and u3 < obj and vis[u] < vis_ans:
				res = u3
				ans = vis[u], res
				vis_ans = vis[u]


		if u1 < a:
			if u2 > 0:
				suma = u1 + u2
				v1 = min(suma, a)
				v2 = max((u1 + u2) - a, 0)
				v3 = u3
				fill = abs(v2 - u2)
				v = (v1, v2, v3)
				if v not in vis or (v in vis and vis[u] + fill < vis[v]):
					vis[v] = vis[u] + fill
					q.append((v1, v2, v3))
			if u3 > 0:
				suma = u1 + u3
				v1 = min(suma, a)
				v3 = max((u1 + u3) - a, 0)
				v2 = u2
				fill = abs(v3 - u3)
				v = (v1, v2, v3)
				if v not in vis or (v in vis and vis[u] + fill < vis[v]):
					vis[v] = vis[u] + fill
					q.append((v1, v2, v3))

		if u2 < b:
			if u1 > 0:
				suma = u1 + u2
				v2 = min(suma, b)
				v1 = max((u1 + u2) - b, 0)
				v3 = u3
				fill = abs(v1 - u1)
				v = (v1, v2, v3)
				if v not in vis or (v in vis and vis[u] + fill < vis[v]):
					vis[v] = vis[u] + fill
					q.append((v1, v2, v3))
			if u3 > 0:
				suma = u2 + u3
				v2 = min(suma, b)
				v3 = max((u2 + u3) - b, 0)
				v1 = u1
				fill = abs(v3 - u3)
				v = (v1, v2, v3)
				if v not in vis or (v in vis and vis[u] + fill < vis[v]):
					vis[v] = vis[u] + fill
					q.append((v1, v2, v3))

		if u3 < c:
			if u2 > 0:
				suma = u3 + u2
				v3 = min(suma, c)
				v2 = max((u3 + u2) - c, 0)
				v1 = u1
				fill = abs(v2 - u2)
				v = (v1, v2, v3)
				if v not in vis or (v in vis and vis[u] + fill < vis[v]):
					vis[v] = vis[u] + fill
					q.append((v1, v2, v3))
			if u1 > 0:
				suma = u1 + u3
				v3 = min(suma, c)
				v1 = max((u1 + u3) - c, 0)
				v2 = u2
				fill = abs(v1 - u1)
				v = (v1, v2, v3)
				if v not in vis or (v in vis and vis[u] + fill < vis[v]):
					vis[v] = vis[u] + fill
					q.append((v1, v2, v3))

	if ans[0] == float("inf"):
		ans[0] = 0

	return ans

def main():
	cases = int(input())

	for i in range(cases):
		line = stdin.readline().strip().split()
		a, b, c, d = tuple(map(int, line))
		n, dp = bfs((a, b, c), d)
		print(str(n) + " " + str(dp))

main()