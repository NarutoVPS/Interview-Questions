#include <bits/stdc++.h>

using namespace std;

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
