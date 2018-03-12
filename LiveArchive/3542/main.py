def solve_slow(a):
    if a <= 1:
        return False
    for b in range(2, a + 1):
        if a % b == 0:
            if b % 10 != 3:
                return False
            else:
                while a % b == 0:
                    a /= b
                if a == 1:
                    return True


def solve(a):
    if a <= 1:
        return False
    b = 2
    while a > 1:
        if a % b == 0:
            if b % 10 != 3:
                return False
            while a % b == 0:
                a /= b
        b += 1
    return True

# while True:
#     a = int(input())
#     if a == -1:
#         break
#     print("{0} {1}".format(a, "YES" if solve(a) else "NO"))

for i in range(10000):
     print("{0} {1}".format(i, "YES" if solve(i) else "NO"))
