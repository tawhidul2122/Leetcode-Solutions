// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination

class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        rowCount = len(grid)
        colCount = len(grid[0])
        
        stack = [(0, 0, k)] 
        visited = {(0, 0, k)}
        steps = 0
        while stack:
            newStack = []
            for x, y, r in stack:
                if x == rowCount - 1 and y == colCount - 1:
                    return steps
                
                for i, j in (x, y+1), (x, y-1), (x+1, y), (x-1, y):
                    if 0 <= i < rowCount and 0 <= j < colCount:
                        if grid[i][j] == 0:
                            node = (i, j, r)
                            if node not in visited:
                                visited.add(node)
                                newStack.append(node)
                                
                        elif r > 0:
                            node = (i, j, r-1)
                            if node not in visited:
                                visited.add(node)
                                newStack.append(node)
                                
            stack = newStack
            steps += 1
            
        return -1