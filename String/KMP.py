""" Question Source : https://leetcode.com/problems/implement-strstr/submissions/ """

class Solution:
    def computePattern(self,needle,pattern):
        j = 1
        i = 0
        n = len(needle)
        while j < n:
            if needle[i] == needle[j]:
                pattern[j] = i+1
                i += 1
                j += 1
            else:
                if i != 0:
                    i = pattern[i - 1]
                else:
                    pattern[j] = 0
                    j += 1
                    
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle) == 0:
            return 0
        pattern = [0]* len(needle)
        self.computePattern(needle,pattern)
        n = len(needle)
        m = len(haystack)
        i = 0
        j = 0
        # start = -1
        found = False
        while i < m:
            if needle[j] == haystack[i]:
                i += 1
                j += 1
                if j == n:
                    return i-j
            else:
                if j != 0:
                    j = pattern[j - 1]
                else:
                    i += 1
        return -1
                    
                    
                
        
