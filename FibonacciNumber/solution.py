'''
    In mathematics, the Fibonacci series is defined by the following recurrence relation:
    F(0) = 0
    F(1) = 1

    F(n) = F(n-1) + F(n-2)

    i.e. nth element is formed by adding elements at (n-1) and (n-2)
    So, first 10 fibonacci numbers will be:
        0, 1, 1, 2, 3, 5, 8, 13, 21, 34

    Given a number n, find F(n).
    Example:
        Input: 6
        Output: 8
        Input: 10
        Output: 55
'''

# O(2^n) Time | O(n) Space
def solve(n):
    if n < 1:
        return -1;
    if n == 1 or n == 2:
        return 1;
    return solve(n-1) + solve(n-2)

# O(n) Time | O(n) Space
cache = dict()
def solve2(n):
    global cache
    cache[1] = 1
    cache[2] = 1

    if n < 1:
        return -1
    if n in cache:
        return cache[n]
    else:
        cache[n] = solve2(n-1) + solve2(n-2)
        return cache[n]

# O(n) Time | O(1) Space
def solve3(n):
    previous = [1, 1]
    i = 3

    while i <= n:
        next  = previous[0] + previous[1]
        previous[0] = previous[1]
        previous[1] = next
        i += 1

    return previous[1] if n > 1 else previous[0]
