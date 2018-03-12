def is_lucky(num):
	num_s = str(num)
	for ch in num_s:
		if ch not in '47':
			return False
	return True

N = 1000
n = int(input())
if is_lucky(n):
	print('YES')
else:
	for i in range(4, N+1):
		if is_lucky(i) and (n % i == 0):
			print('YES')
			break
	else:
		print('NO')