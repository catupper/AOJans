def fact(x):
    res = 1
    for i in xrange(1, x + 1):
        res *= i
    return res

def comb(a, b):
    if(a < b or b < 0):return 0
    if(b == 0):return 1
    return fact(a)/fact(b)/fact(a-b)

a, b, c = map(int, raw_input().split())
c -= a * b
print comb(c + a - 1, c)

