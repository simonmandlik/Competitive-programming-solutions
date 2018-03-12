def prime(n):
	if n == 1:
		return False
	if n <= 3:
		return True
	if n % 2 == 0:
		return False
	if n <= 8:
		return True
	if n % 3 == 0:
		return False
	else:
		f = 5
		while f*f <= n:
			if n%f == 0 or n%(f+2) == 0:
				return False
			f+=6
		return True

N, M = list(map(int, input().split()))

for i in range(N+1, M+1):
	if prime(i):
		if i == M:
			print('YES')
		else:
			print('NO')
		break
else:
	print('NO')