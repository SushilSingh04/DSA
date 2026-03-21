t = int(input())
for i in range(t):
	[a,b] = list(map(int, input().split(" ")))
	lst = [True] * (b+1)
	lst[0] = False
	lst[1] = False
	
	p = 2
	while p*p <= b:
		if lst[p]:
			for i in range(p*p, b+1, p):
				lst[i] = False
		p+=1
	
	for j in range(a, b+1):
		if lst[j]:
			print(j, end=" ")