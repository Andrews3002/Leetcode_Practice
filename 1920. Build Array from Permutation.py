class Solution(object):
    def buildArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        ans = list(nums)
        
        for i in range(0,len(nums)):
            ans[i] = nums[nums[i]]
        
        return ans
        
