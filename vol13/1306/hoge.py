def fact(a):
    if a == 0:return 1
    return a * fact(a - 1)

n, m = map(int, raw_input().split())

print fact(n + m) / fact(n) / fact(m)
