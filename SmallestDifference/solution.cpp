#include <bits/stdc++.h>

using namespace std;

// O(nlog(n) + mlog(m)) time | O(1) space where n,m are length of arr1 & arr2 respectively.

pair<int, int> solve(vector<int> &arr1, vector<int> &arr2){
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int i{}, j{}, minDiff{INT_MAX};
    pair<int, int> minPair;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i] == arr2[j])
            return make_pair(arr1[i], arr2[j]);
        else {
            if(abs(arr1[i] - arr2[j]) < minDiff){
                minDiff = abs(arr1[i] - arr2[j]);
                minPair.first = arr1[i];
                minPair.second = arr2[j];
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
    cout<<ans.first<<" "<<ans.second<<endl;
}