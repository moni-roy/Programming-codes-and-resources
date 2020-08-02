class Solution:
    def addBinary(self, a: str, b: str) -> str:
        A = int(a, 2)
        B = int(b, 2)
        A = A+B
        return str(bin(A)[2:])
