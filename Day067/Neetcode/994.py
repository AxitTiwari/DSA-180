from collections import deque
from typing import List

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:

        ## create a queue for BFS
        q = deque()

        ## keep track of fresh oranges
        time, fresh = 0, 0

        ROW, COL = len(grid), len(grid[0])
        for r in range(ROW):
            for c in range(COL):
                ## get the count of fresh oranges
                if grid[r][c] == 1:
                    fresh += 1

                ## if any rottan orange spotted, put inside the queue
                if grid[r][c] == 2:
                    q.append([r, c])

        ## one rottan orange can make other fresh oranges rottan in 4 direction in 1 sec.
        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        while q and fresh > 0:

            ## pop all the rottan oranges(present in grid right now), because they are going
            ## to make other as rottan, at same time
            for i in range(
                len(q)
            ):  ## snapshot (len(q) is a snapshot, only calculated once)

                ## get the rottan orange coordinates
                r, c = q.popleft()

                ## check for all 4 directions and make fresh -> rottan
                for dr, dc in directions:
                    row, col = dr + r, dc + c

                    ## edge cases, not fresh to make rottan, out of bound
                    if (
                        (row < 0 or row == len(grid))
                        or 
                        (col < 0 or col == len(grid[0]))
                        or 
                        grid[row][col] != 1
                    ):
                        continue

                    ## make fresh oranges rottan
                    grid[row][col] = 2
                    q.append([row, col])
                    fresh -= 1
            ## time will be incremented only after from all sides all rottan oranges will
            ## make other as rottan
            time += 1
        return time if fresh == 0 else -1