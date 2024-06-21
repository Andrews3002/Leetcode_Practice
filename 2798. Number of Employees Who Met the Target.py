class Solution(object):
    def numberOfEmployeesWhoMetTarget(self, hours, target):
        """
        :type hours: List[int]
        :type target: int
        :rtype: int
        """
        ans = 0

        for i in hours:
            if i >= target:
                ans = ans + 1
        
        return ans
        
