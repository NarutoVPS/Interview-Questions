#include <bits/stdc++.h>
using namespace std;

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
