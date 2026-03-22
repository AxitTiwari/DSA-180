from typing import List
import heapq

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        
        ## total number of nodes
        N = len(points)

        ## create adjancency list from points
        adj = { i : [] for i in range(N)} # i : list of [cost, node]
        for i in range(N):

            x1, y1 = points[i]

            for j in range(i+1, N):
                x2, y2 = points[j]
                dist = abs(x1 - x2) + abs(y1 - y2)
                adj[i].append([dist, j])
                adj[j].append([dist, i])
            
        ## prim's Algorithm
        res = 0
        visit = set()
        min_h = [[0, 0]] ## [cost, point]

        while len(visit) < N:

            ## this node 'i' is having the minimum cost among all nodes in min heap
            cost, i = heapq.heappop(min_h)

            ## node already visited
            if i in visit:
                continue
            
            ## add cost, and mark node visited
            res += cost
            visit.add(i)

            ## process for neighbours
            for nei_cost, nei in adj[i]:

                ## if not visited neighbour 'nei' push in min_heap
                if nei not in visit:
                    heapq.heappush(min_h, [nei_cost, nei])

        ## return minimum cost to conect all points
        return res