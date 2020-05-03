class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        note, maga = Counter(ransomNote), Counter(magazine)
        for c in note:
            if c not in maga or note[c]>maga[c]:
                return False
        return True