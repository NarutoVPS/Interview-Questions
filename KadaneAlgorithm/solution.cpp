/*
    Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

    Example:
        Input: [-2,1,-3,4,-1,2,1,-5,4],
        Output: 6
        Explanation: [4,-1,2,1] has the largest sum = 6.
*/

#include <bits/stdc++.h>
using namespace std;

// O(n) time | O(1) space
int solve(const vector<int> &arr){
    if (!arr.size())
        return 0;
    if (arr.size() == 1)
        return arr[0];
    
    int maxSum{arr[0]}, currentSum{arr[0]};
    for(int i{1}; i<arr.size(); i++){
        currentSum = max(currentSum + arr[i], arr[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}
