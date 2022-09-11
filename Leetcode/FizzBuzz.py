class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        m = n
        ans = []
        for n in range(1, m + 1):
            if n % 3 == 0 and n % 5 == 0: ans.append("FizzBuzz")
            elif n % 3 == 0: ans.append("Fizz")
            elif n % 5 == 0: ans.append("Buzz")
            else: ans.append(str(n))
        return ans