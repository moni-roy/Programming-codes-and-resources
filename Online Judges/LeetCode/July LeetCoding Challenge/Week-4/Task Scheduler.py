class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        count = Counter(tasks)
        mx = count.most_common()[0]
        idles = n*(mx[1]-1)
        for i in range(26):
            if chr(i + ord('A')) != mx[0]:
                idles -= min(mx[1]-1, count[chr(i + ord('A'))])
        return len(tasks) + max(0, idles)
