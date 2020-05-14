/*
    Given an array of positive numbers, find the maximum sum of a subsequence with the constraint that no 2 numbers in the sequence should be adjacent in the array. 
    So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7).

    Examples :
        Input : arr[] = {5, 5, 10, 100, 10, 5}
        Output : 110

        Input : arr[] = {1, 2, 3}
        Output : 4

        Input : arr[] = {1, 20, 3}
        Output : 20
*/

#include <bits/stdc++.h>
using namespace std;

// O(n) time | O(n) space
int solve(const vector<int> &arr){
    if(!arr.size())
        return 0;
    if(arr.size()==1)
        return arr[0];
    vector<int> maxSum {arr};
    maxSum[1] = (arr[0] > arr[1])? arr[0]: arr[1];
    for(int i{2}; i<maxSum.size(); i++){
        maxSum[i] = max(maxSum[i-1], maxSum[i-2] + maxSum[i]);
    }
    return maxSum[maxSum.size()-1];
}



