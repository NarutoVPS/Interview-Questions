/*
    We are given an array of integers and a range, we need to find whether the subarray which falls in this range has values in the form of a mountain or not. 
    All values of the subarray are said to be in the form of a mountain if either all values are increasing or decreasing or first increasing and then decreasing.

    More formally a subarray [a1, a2, a3 … aN] is said to be in form of a mountain if there exist an integer K, 1 <= K <= N such that,
    a1 <= a2 <= a3 .. <= aK >= a(K+1) >= a(K+2) …. >= aN

    Example 1:
        Input: [2,1,4,7,3,2,5]
        Output: 5
        Explanation: The largest mountain is [1,4,7,3,2] which has length 5.

    Example 2:
        Input: [2,2,2]
        Output: 0
        Explanation: There is no mountain.
*/

#include <bits/stdc++.h>
using namespace std;

// O(n) time | O(1) space
int solve(const vector<int> &arr){
    // if the length of arr is less than 3, no peak exists
    if(arr.size() < 3)
        return 0;

    int maxPeak{}, current{1};

    // traverse through the array
    while(current < arr.size()-1){
        // check if current element is a peak
        if(arr[current] - arr[current-1] > 0 && arr[current] - arr[current+1] > 0){
            int count{1}, i{current};
            // count the elements that are decreasing at left side of the peak
            while(i > 0 && arr[i] - arr[i-1] > 0){
                count++;
                i--;
            }

            i = current;
            // count the elements that are decreasing at right side of the peak
            while(i < arr.size()-1 && arr[i] - arr[i+1] > 0){
                count++;
                i++;
            }
            // continue traversing the array from the end of the current peak
            current = i;
            
            // if the length of current peak is greater than maxPeak, update maxPeak
            maxPeak = max(maxPeak, count);
        }
        else
            current++;     
    }
    return maxPeak;
}       
