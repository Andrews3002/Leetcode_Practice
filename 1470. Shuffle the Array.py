class Solution(object):
    def shuffle(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: List[int]
        """
        result = list(nums)
        
        k = 0
        
        for i in range(0,n):
            result[k] = nums[i]
            result[k+1] = nums[i+n]
            k = k + 2
        
        return result
    
        
      
    
        

    
    
    
