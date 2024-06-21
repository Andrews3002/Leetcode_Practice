class Solution(object):
    def numIdenticalPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        pairs = 0
        
        for i in range(0,len(nums)):
            for k in range(i+1,len(nums)):
                if nums[i] == nums[k]:
                    pairs+=1
        
        
        return pairs
        
