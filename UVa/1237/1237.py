T = int(input(""))
i = 0
while i < T:
	data = []
	D = int(input(""))
	z =0
	while z < D:
		inf = input("")
		inf = inf.split(" ")
		data.append(inf)
		z += 1
	Q = int(input(""))
	p = 0
	while p < Q:
		P = int(input(""))
		u = 0
		c = 0 
		ans = ""
		while u < D:
			if P >= int(data[u][1]) and P <= int(data[u][2]):
				c += 1
				ans = data[u][0]
			u +=1
		if c == 1:
			print(ans)
		else:
			print("UNDETERMINED")	
		p +=1
	if(i != T - 1):
		print("")
	i+=1
