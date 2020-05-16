/*
    We are given an array of integers and a range, we need to find whether the subarray which falls in this range has values in the form of a mountain or not. 
    All values of the subarray are said to be in the form of a mountain if either all values are increasing or decreasing or first increasing and then decreasing.

    More formally a subarray [a1, a2, a3 … aN] is said to be in form of a mountain if there exist an integer K, 1 <= K <= N such that,
    a1 <= a2 <= a3 .. <= aK >= a(K+1) >= a(K+2) …. >= aN

    Examples:
        Input : Arr[]  = [2 3 2 4 4 6 3 2], Range = [0, 2]
        Output :  Yes

        Explanation: The output is yes , subarray is [2 3 2], 
        so subarray first increases and then decreases

        Input:  Arr[] = [2 3 2 4 4 6 3 2], Range = [2, 7]
        Output: Yes

        Explanation: The output is yes , subarray is [2 4 4 6 3 2], 
        so subarray first increases and then decreases


        Input: Arr[]= [2 3 2 4 4 6 3 2], Range = [1, 3]
        Output: no

        Explanation: The output is no, subarray is [3 2 4], 
        so subarray is not in the form above stated
*/

#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int> &arr){
    if(arr.size() < 3)
        return 0;

    int maxPeak{}, current{1};

    while(current < arr.size()-1){
        if(arr[current] - arr[current-1] > 0 && arr[current] - arr[current+1] > 0){
            int count{1}, i{current};
            while((arr[i] - arr[i-1] > 0) && (i > 0)){
                count++;
                i--;
            }

            i = current;
            while((arr[i] - arr[i+1] > 0) && (i < arr.size()-1)){
                count++;
                i++;
            }
            current = i;

            maxPeak = max(maxPeak, count);
        }
        else
            current++;     
    }
    return maxPeak;
}       
