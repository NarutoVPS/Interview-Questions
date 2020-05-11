#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

/*
                    Naive Approach
                O(n^2) time | O(1) space
pair<int, int> solve(const vector<int> &arr, const int &target) {
    for(int i{}; i<arr.size(); i++){
        for(int j{i+1}; j<arr.size(); j++){
            if(arr[i]+arr[j] == target)
                return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}
*/


//                Better Approach--> O(n) time | O(n) space
pair<int, int> solve(const vector<int> &arr, const int &target) {
    unordered_map<int, int> available;
    int currentNum{};
    for(int i{}; i<arr.size(); i++){
        currentNum = arr[i];
        if(available.find(target-currentNum) != available.end())
            return make_pair(available[target-currentNum], i);
        else
            available[currentNum] = i;
    }
    return make_pair(-1, -1);
}

int main() {
    vector<int> arr {4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8};
    auto ans = solve(arr, -3);
    cout<<ans.first<<" "<<ans.second<<endl;

    return 0;
}