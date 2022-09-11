class Solution:
    def numberOfSteps(self, num: int) -> int:
        ans = 0
        while num:
            if num % 2 == 0:
                num /= 2
            else:
                num -= 1
            ans += 1
        return ans