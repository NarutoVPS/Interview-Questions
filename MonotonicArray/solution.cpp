/*
    An array is monotonic if it is either monotone increasing or monotone decreasing.

    An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

    Return true if and only if the given array A is monotonic.

        Example 1:
            Input: [1,2,2,3]
            Output: true

        Example 2:
            Input: [6,5,4,4]
            Output: true

        Example 3:
            Input: [1,3,2]
            Output: false

        Example 4:
            Input: [1,2,4,5]
            Output: true

        Example 5:
            Input: [1,1,1]
            Output: true
*/

#include <bits/stdc++.h>
using namespace std;

// O(n) time | O(1) space
bool solve(const vector<int> &arr){
    if(arr.size() < 3)
        return true;
    int direction = arr[1] - arr[0];
    for(int i{2}; i < arr.size(); i++){
        if(direction == 0){
            direction = arr[i] - arr[i-1];
            continue;
        }
        if(direction < 0){
           if(arr[i] - arr[i-1] > 0)
                return false; 
        }
        else if(arr[i] - arr[i-1] < 0)
            return false;
    }
    return true;
}



// O(n) time | O(1) space (much simpler version)
bool solve2(const vector<int> &arr){
    bool isIncreasing  = true;
    bool isDecreasing = true;

    for(int i{}; i<arr.size(); i++){
        if(arr[i] - arr[i-1] > 0)
            isDecreasing = false;
        else if (arr[i] - arr[i-1] < 0)
            isIncreasing = false;
    }
    return true;
}
