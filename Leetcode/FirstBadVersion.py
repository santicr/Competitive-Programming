# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        def binSearch(low, high):
            while(low + 1 < high):
                m = (low + high) // 2
                if isBadVersion(m):
                    high = m
                else:
                    low = m
            return high
        
        return binSearch(0, n)