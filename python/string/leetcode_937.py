# LeetCode
# 937. Reorder Data in Log Files
# https://leetcode.com/problems/reorder-data-in-log-files/

# 직접 정렬하여 람다식 사용한 방법
def mySolution(logs):

	# 가장 앞부분이 식별자
	# 문자로 구성된 로그가 숫자 로그보다 앞에 -> 문자가 앞에
	# 식별자는 순서에 영향 X, 문자가 동일할 경우 식별자 순으로
	# 숫자 로그는 입력 순서대로 함 -> 숫자는 먼저 나온 것부터
 
	# 문자와 숫자를 구분해서 관리해야 해야 함.

	stringArray = []
	numberArray = []

	for log in logs:
		tempString = log
		tempArray = tempString.split(" ")
				
		if tempArray[1].isalpha():
			stringArray.append(tempString)
		else:
			numberArray.append(tempString)

		stringArray.sort(key=lambda x: (x.split(" ", 1)[1], x.split(" ", 1)[0]))

		for number in numberArray:
			stringArray.append(number)
			
	return stringArray

def otherSolution(logs):
	stringArray = []
	numberArray = []

	for log in logs:
		tempString = log
		tempArray = tempString.split(" ")
		
		if tempString.split()[1].isalpha():
			stringArray.append(tempString)
		else:
			numberArray.append(tempString)

		stringArray.sort(key=lambda x: (x.split()[1:], x.split()[0]))
			
	return stringArray+numberArray

print(mySolution(["a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog", "a8 act zoo"]))
print(otherSolution(["a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog", "a8 act zoo"]))