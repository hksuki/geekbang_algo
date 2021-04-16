class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0 :
            return self.myPow(1/x, -n)
        if n == 0:
            return 1
        sub = self.myPow(x, n//2)
        value = sub * sub
        if n % 2 == 0:
            return value
        else:
            return value * x

if __name__ == "__main__":
    sol = Solution()
    print(sol.myPow(2.0, 10))