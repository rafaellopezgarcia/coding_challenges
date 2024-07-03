from typing import Optional, List
from collections import deque 

class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        # Do BFS
        # Add each node value to a cumulative sum
        # Once the level is completed, compute the mean based on 
        # the cumulative sum
        if root is None:
            return []

        dq = deque()
        dq.append(root)
        out = []
        while dq:
            n = len(dq)
            cumsum = 0
            for _ in range(n):
                node = dq.popleft()
                cumsum += node.val
                if node.left:
                    dq.append(node.left)
                if node.right:
                    dq.append(node.right)
                
            out.append(cumsum/n)
        return out