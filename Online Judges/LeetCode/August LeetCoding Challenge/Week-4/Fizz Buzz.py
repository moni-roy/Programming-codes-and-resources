class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        i = 1
        ans = []
        while i <= n:
            if i % 15 == 0:
                ans.append("FizzBuzz")
            elif i % 5 == 0:
                ans.append("Buzz")
            elif i % 3 == 0:
                ans.append("Fizz")
            else:
                ans.append(str(i))
            i += 1
        return ans
