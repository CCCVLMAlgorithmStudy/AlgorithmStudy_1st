def my_change124(n):
    li = ['4', '1', '2']
    s = ''
    while n > 0:
        s += li[n%3]
        if n%3==0: n -= 1
        n //= 3
    return s[::-1]

print(my_change124(13))
