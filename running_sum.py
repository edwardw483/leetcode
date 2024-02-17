from typing import List
def runningSum(nums: List[int]) -> List[int]:
    newList =  []
    entry = 0
    for i in nums:
        entry += i
        newList.append(entry)
    return newList

print(runningSum([1,2,3,4]))

def findLeastNumOfUniqueInts(arr: List[int], k: int) -> int:
    alpha = {}
    for i in arr:
        temp = alpha.setdefault(i, 0)
        alpha[i] = temp + 1
    print(alpha)
    return 1

print(findLeastNumOfUniqueInts([1, 2, 3], 1))