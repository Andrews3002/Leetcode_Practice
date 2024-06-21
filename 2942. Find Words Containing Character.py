class Solution(object):
    def findWordsContaining(self, words, x):
        """
        :type words: List[str]
        :type x: str
        :rtype: List[int]
        """
        
        output = []
        temp = "temp"
        
        for i in range(0,len(words)):
            temp = words[i]
            for k in range(0,len(temp)):
                if temp[k] == x:
                    output.append(i)
                    break
        
        return output
                
        
