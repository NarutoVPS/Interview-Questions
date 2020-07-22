#include <bits/stdc++.h>
using namespace std;

template <typename T>
int solve(vector<T> arr, int multiplier = 1) {
    int sum{};

    for (auto each : arr) {
        try {
            sum += each;
        }
        catch (...) {
            sum += solve(arr, multiplier + 1);
        }
    }

    return sum;
}

