def solve(mainArr, subArr):
	mainArrIndex = subArrIndex = 0

	while mainArrIndex < len(mainArr) and subArrIndex < len(subArr):
		if mainArr[mainArrIndex] == subArr[subArrIndex]:
			subArrIndex += 1
		mainArrIndex += 1

	return subArrIndex == len(subArr)
