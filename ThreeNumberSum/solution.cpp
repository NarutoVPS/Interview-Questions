#include <bits/stdc++.h>

using namespace std;

/*
    Naive Approach--> O(n^3) time | O(1) space
vector<vector<int>> solve(const vector<int> &arr, const int &target) {
    vector<vector<int>> ans;
    for(int i{}; i<arr.size(); i++){
        for(int j{i+1}; j<arr.size(); j++){
            for(int k{j+1}; k<arr.size(); k++){
                if(arr[i]+arr[j]+arr[k] == target)
                    ans.push_back({arr[i], arr[j], arr[k]});
            }
        }
    }
    return ans;
}
*/

//  Better Approach O(n^2) time | O(n) space
vector<vector<int>> solve(vector<int> &arr, const int &target){
    sort(arr.begin(), arr.end());
    int currentSum{};
    vector<vector<int>> ans;
    for(int i{}; i<arr.size()-2; i++){
        int left{i+1}, right = arr.size()-1;
        int currentNum = arr[i];
        while(left < right){
            currentSum = currentNum + arr[left] + arr[right];
            if(currentSum == target){
                ans.push_back({currentNum, arr[left], arr[right]});
                left++;
                right--;
            }
            else if(currentSum < target)
                left++;
            else
                right--;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {-1, 0, 1, 2, -2, -4};
    auto ans = solve(arr, 0);
    if(ans.size()){
        for(auto each:ans){
            for(auto x:each)
                cout<<x<<" ";
            cout<<"\n";
        }
    }
    return 0;
}

/*
    Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = target? 
    Find all unique triplets in the array which gives the sum of target.

    Given array nums = [-1, 0, 1, 2, -1, -4] and target = 0

        A solution set is:
        [
            [-1, 0, 1],
            [-1, -1, 2]
        ]
*/