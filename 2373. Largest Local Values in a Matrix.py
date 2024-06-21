class Solution(object):
    def largestLocal(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        n = len(grid)

        maxLocal = []
        largest = 0
        baseY = 0
        

        for baseY in range(n-2):
            r = []
            baseX = 0
            for baseX in range(n-2):
                for i in range(baseY, baseY+3):
                    for j in range(baseX, baseX+3):
                        if grid[i][j] > largest:
                            largest = grid[i][j]
                r.append(largest)
                largest = 0
            maxLocal.append(r) 

        return maxLocal


        
