/*
    Given an array, move all occurances of a specified element "target" at the end of the array keeping the relative positon between the elements.
    You must do this in-place without making a copy of the array.

    Example:

        Input: [0,1,0,3,12]
        Output: [1,3,12,0,0]
*/

#include <bits/stdc++.h>
using namespace std;

/*
    O(n) time | O(1) space However this approach doesn't preserve relative position between elements

    void solve(vector<int> &arr, const int &target){
        int i{};
        int j = arr.size() - 1;

        while(i < j){
            while(i < j && arr[j] == target)
                j--;
            if(arr[i] == target)
                swap(arr[i], arr[j]);
            i++;
        }
    }
*/



// O(n) time | O(1) space This approach preserves relative position between elements
void solve(vector<int> &arr, const int &target){
    int i{};
    for(int current{}; current < arr.size(); current++){
        if(arr[current] != target){
            swap(arr[i], arr[current]);
            i++;
        }
    }
}

int main(){
    vector<int> arr {0,1,0,3,12};
    solve(arr, 0);
    for(auto each:arr)
        cout<<each<<" ";
}