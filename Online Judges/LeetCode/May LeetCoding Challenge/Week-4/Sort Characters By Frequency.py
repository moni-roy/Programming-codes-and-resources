class Solution:
    def frequencySort(self, s: str) -> str:
        frequency = Counter(s)
        return "".join([char * times for char, times in frequency.most_common()])
