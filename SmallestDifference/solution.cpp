#include <bits/stdc++.h>

using namespace std;

/*
    Naive Approach--> O(n^2) time | O(1) space

vector<int> solve(vector<int> &arr1, vector<int> &arr2) {
    int minDiff{INT_MAX};
    vector<int> minPair;
    for(int i{}; i<arr1.size(); i++){
        for(int j{}; j<arr2.size(); j++){
            if(abs(arr1[i]-arr2[j]) < minDiff){
                minDiff = abs(arr1[i]-arr2[j]);
                minPair = {arr1[i], arr2[j]};
            }
        }
    }
    return minPair;
}
*/



// Better Approach--> O(nlog(n) + mlog(m)) time | O(1) space where n,m are length of arr1 & arr2 respectively.

vector<int> solve(vector<int> &arr1, vector<int> &arr2){
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int i{}, j{}, minDiff{INT_MAX};
    vector<int> minPair;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i] == arr2[j])
            return {arr1[i], arr2[j]};
        else {
            if(abs(arr1[i] - arr2[j]) < minDiff){
                minDiff = abs(arr1[i] - arr2[j]);
                minPair = {arr1[i], arr2[j]};
            } 
            if(arr1[i] < arr2[j])
                i++;
            else
                j++;
        }
    }
    return minPair;
}

int main(){
    vector<int> A {1, 2, 11, 5};
    vector<int> B {4, 12, 19, 23, 127, 235};
    auto ans = solve(A, B);
    for(auto each:ans)
        cout<<each<<" ";
}


/*
Given two non-empty arrays of integers, find the pair of values (one value from each array) with the smallest (non-negative) difference.

Example

    Input: [1, 3, 15, 11, 2], [23, 127, 235, 19, 8]

    Output: [11, 8]; this pair has the smallest difference.
*/