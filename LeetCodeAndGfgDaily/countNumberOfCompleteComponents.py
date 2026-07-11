from collections import defaultdict, deque
from typing import List

class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        mp = defaultdict(list)
        for [a, b] in edges:
            mp[a].append(b)
            mp[b].append(a)

        visited = [False]*n
        n_complete_connected = 0
        for V in range(n):
            if not visited[V]:
                n_vertices = 0
                n_edges = 0
                q = deque([V])
                visited[V] = True
                while q:
                    n_vertices += 1
                    node = q.popleft()
                    for nei_node in mp[node]:
                        n_edges += 1
                        if not visited[nei_node]:
                            q.append(nei_node) 
                            visited[nei_node] = True
                            
                if n_vertices*(n_vertices - 1) == n_edges:
                    n_complete_connected += 1
        
        return n_complete_connected





