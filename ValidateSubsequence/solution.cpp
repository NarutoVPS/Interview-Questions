/*
Given two arrays, check if the 2nd array is a valid subsequence of the 1st array.
To be a valid subsequence all the elements in 2nd array must be present in 1st array.
The elements of the 2nd array must preserve its relative positions.
*/

#include <bits/stdc++.h>

using namespace std;

// O(n) time | O(1) space
bool solve(const vector<int> &mainArray, const vector<int> &subArray){
	int mainArrayIndex{}, subArrayIndex{};
	while(mainArrayIndex < mainArray.size() && subArrayIndex < subArray.size()) {
		if (mainArray[mainArrayIndex] == subArray[subArrayIndex]){
			// if the element in the subArray is found in the mainArray, iterate the subArray
			subArrayIndex++;
		}
		// keep iterating over the mainArray
		mainArrayIndex++;
	}
	// if all the elements are found then the value of j will be equal to the length of subArray
	return subArrayIndex == subArray.size();
}
