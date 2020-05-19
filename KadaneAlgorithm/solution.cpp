#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int> &arr){
    if (!arr.size())
        return 0;
    if (arr.size() == 1)
        return arr[0];
    
    int maxSum{INT_MIN}, currentSum{arr[0]};
    for(int i{1}; i<arr.size(); i++){
        currentSum = max(currentSum, arr[i]);
        if (currentSum > maxSum)
            maxSum = currentSum;
    }

    return maxSum;
}