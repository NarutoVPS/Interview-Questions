'''
	Given two arrays, check if the 2nd array is a valid subsequence of the 1st array.
	To be a valid subsequence all the elements in 2nd array must be present in 1st array.
	The elements of the 2nd array must preserve its relative positions.
'''

# O(n) time | O(1) space
def solve(mainArr, subArr):
	mainArrIndex = subArrIndex = 0

	while mainArrIndex < len(mainArr) and subArrIndex < len(subArr):
		if mainArr[mainArrIndex] == subArr[subArrIndex]:
			subArrIndex += 1
		mainArrIndex += 1

	return subArrIndex == len(subArr)
