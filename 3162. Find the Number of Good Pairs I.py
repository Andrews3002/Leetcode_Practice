class Solution(object):
    def numberOfPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: int
        """

        goodPairs = 0

        for i in range(0,len(nums1)):
            for j in range(0,len(nums2)):
                divTest = nums2[j]*k
                if nums1[i]%divTest == 0:
                    goodPairs = goodPairs + 1
        
        return goodPairs
        
