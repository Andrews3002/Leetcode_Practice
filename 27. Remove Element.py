""""
nums = [0,1,2,2,3,0,4,2]
val = 2
k = 0

oldnums = nums

nums = []

for i in oldnums:
    if i != val:
        nums.append(i)
        k = k + 1

for i in range(k,len(oldnums)):
    nums.append("_")

print(k)
print(nums)
"""
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """

        k = i = 0

        while i < len(nums):
            if nums[i] == val:
                nums.pop(i)
                k = k+1
                continue
            else:
                k = k+1
            
            i = i + 1
        
        return k
        
