from collections import defaultdict, deque
from typing import List

class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0] 
       
        adj_list = defaultdict(set)
        for u, v in edges:
            adj_list[u].add(v)
            adj_list[v].add(u)


        leaves = deque([node for node in adj_list if len(adj_list[node]) == 1])

        while n > 2:
            num_leaves = len(leaves)
            n -= num_leaves
            for _ in range(num_leaves):
                leaf = leaves.popleft()
                neighbor = adj_list[leaf].pop()
                adj_list[neighbor].remove(leaf)  
                if len(adj_list[neighbor]) == 1:
                    leaves.append(neighbor)

        return list(leaves)  
