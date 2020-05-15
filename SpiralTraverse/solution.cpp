/*
    Given a 2-dimensional array or a matrix, we have to traverse the given matrix in spiral order.

    Example 1:
        Input:
        [
        [ 1, 2, 3 ],
        [ 4, 5, 6 ],
        [ 7, 8, 9 ]
        ]
        Output: [1,2,3,6,9,8,7,4,5]

    Example 2:
        Input:
        [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9,10,11,12]
        ]
        Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

#include <bits/stdc++.h>

using namespace std;

// O(n) time | O(n) space
vector<int> solve(const vector<vector<int>> &arr){
    vector<int> ans;
    if(arr.size() < 1)
            return ans;
    if(arr.size() == 1)
        return arr[0];
    int rowStart{}, colStart{};
    int rowEnd = arr.size() - 1;
    int colEnd = arr[0].size() - 1;

    while (rowStart <= rowEnd && colStart <= colEnd){
        for(int i{colStart}; i<=colEnd; i++)
            ans.push_back(arr[rowStart][i]);

        for(int i{rowStart + 1}; i<=rowEnd; i++)
            ans.push_back(arr[i][colEnd]);

        for(int i{colEnd - 1}; i>=colStart; i--){
            if(rowStart == rowEnd)
                break;
            ans.push_back(arr[rowEnd][i]);
        }

        for(int i{rowEnd - 1}; i>rowStart; i--){
            if(colStart == colEnd)
                break;
            ans.push_back(arr[i][colStart]);
        }
        
        rowStart++;
        rowEnd--;
        colStart++;
        colEnd--;
    }

    return ans;
}
