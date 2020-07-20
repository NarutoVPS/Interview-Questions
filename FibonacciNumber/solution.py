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
