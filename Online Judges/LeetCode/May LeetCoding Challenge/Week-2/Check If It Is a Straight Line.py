class Solution:
    
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        if(len(coordinates)<=2):
            return True
        
        def slope(point1: List, point2: List):
            if(point1[0] == point2[0]):
                return 0
            return (point1[1]-point2[1]) / (point1[0]-point2[0])
    
        m = slope(coordinates[0], coordinates[1])
        for i in range(2,len(coordinates)-1):
            tm = slope(coordinates[i], coordinates[i+1])
            if(tm != m):
                return False
        return True