class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        baseColor = image[sr][sc]
        R, C = len(image), len(image[0])
        if(baseColor == newColor):
            return image
        def dfs(x, y):
            if(image[x][y] == baseColor):
                image[x][y] = newColor
                if(x>0): 
                    dfs(x-1, y)
                if(x<R-1):
                    dfs(x+1, y)
                if(y>0): 
                    dfs(x, y-1)
                if(y<C-1):
                    dfs(x, y+1)
        dfs(sr, sc)
        return image