class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        x, y, dx, dy = 0, 0, 0, 1

        for it in instructions:
            if it == 'L':
                dx, dy = -dy, dx
            elif it == 'R':
                dx, dy = dy, -dx
            else:
                x = x + dx
                y = y + dy
        return (x, y) == (0, 0) or (dx, dy) != (0, 1)
