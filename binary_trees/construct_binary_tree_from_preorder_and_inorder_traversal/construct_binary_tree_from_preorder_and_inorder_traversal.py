from typing import List, Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        # Get first element from pre-order - val
        # Find val in in-order
        preorder_idx = 0
        def aux(left, right):
            nonlocal preorder_idx
            if left >= right:
                return None
            val = preorder[preorder_idx]
            preorder_idx +=1
            inorder_idx = inorder.index(val)
            return TreeNode(val, aux(left, inorder_idx), aux(inorder_idx+1, right))
        
        return aux(0, len(preorder))