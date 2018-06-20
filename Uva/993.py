T = int(input())
for t in range(T):
  N = int(input()); res = ""
  if N <= 1:
    print(N)
    continue
  for d in reversed(range(2,10)):
    while N%d == 0:
      N //= d
      res = str(d) + res
  else:
    if N > 1:
      print(-1)
    else:
      print(res)
