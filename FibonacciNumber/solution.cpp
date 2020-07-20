/*
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
*/

#include <bits/stdc++.h>
using namespace std;

// O(2^n) Time | O(n) Space
long long solve(int n) {
    if (n < 1)
        return -1;
    if (n == 1 || n == 2)
        return 1;
    return solve(n-1) + solve(n-2);   
}

// O(n) Time | O(n) Space
long long solve2(int n) {
    static unordered_map<int, long long> cache{};
    cache[1] = 1;
    cache[2] = 1;

    if (n < 1)
        return -1;
    if (cache.find(n) != cache.end())
        return cache[n];
    else {
        cache[n] = solve2(n-1) + solve2(n-2);
        return cache[n];
    }
}

// O(n) Time | O(1) Space
long long solve3(int n) {
    vector<long long> previous = {1, 1};
    int i = 3;

    while (i <= n) {
        long long next = previous[0] + previous[1];
        previous[0] = previous[1];
        previous[1] = next;
        i++;
    }

    return n > 1 ? previous[1] : previous[0];
}
