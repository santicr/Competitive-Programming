def divide(s, j):
	i = j
	st = s[0:j]
	while(i < len(s)):
		if(s[i:j + i] != st):
			return False
		i += j
	return True

def solution(s):
	cads = []

	for i in range(len(s)):
		cads.append(s[i:len(s) + i] + s[0:i])

	ans = -1
	for j in range(len(cads)):	
		for i in range(1, len(s) + 1):
			if(len(s) % i == 0):
				if(divide(s, i)):
					ans = max((len(s)//i), ans)
					break
	return ans

def main():
	s = "abccbaabccba"
	solution(s)

main()