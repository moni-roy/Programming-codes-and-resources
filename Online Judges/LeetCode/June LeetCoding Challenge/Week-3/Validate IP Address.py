class Solution:
    def validIPAddress(self, IP: str) -> str:
        def checkIP4(s: str) -> str:
            nums = s.split('.')
            for num in nums:
                if len(num) == 0 or len(num) > 3:
                    return "Neither"
                if num[0] == '0' and len(num) != 1 or not num.isdigit() or int(num) > 255:
                    return "Neither"
            return "IPv4"

        def checkIP6(s: str) -> str:
            nums = s.split(':')
            digits = "0123456789abcdefABCDEF"
            for num in nums:
                if len(num) == 0 or len(num) > 4:
                    return "Neither"
                if not all(c in digits for c in num):
                    return "Neither"
            return "IPv6"

        if IP.count('.') == 3:
            return checkIP4(IP)
        if IP.count(':') == 7:
            return checkIP6(IP)
        return "Neither"
