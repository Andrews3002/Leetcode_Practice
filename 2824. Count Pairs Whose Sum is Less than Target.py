class Solution(object):
    def countPairs(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        pairs = 0
        n = len(nums)

        for i in range(0,n):
            for j in range(0,n):
                if i == j:
                    continue

                if 0 <= i and i < j and j < n and nums[i] + nums[j] < target:
                    pairs = pairs + 1

        return pairs
        
