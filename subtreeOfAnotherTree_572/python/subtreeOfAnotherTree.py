# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, s, t):
        if s == None:
            return False
        return self.isIdentical(s, t) || self.isSubtree(s.left, t) || self.isSubtree(s.right, t)
        
    def isIdentical(self, s, t):
    	if s == None and t == None:
    		return True
    	if s == None and t not None:
    		return False
    	if s not None and t == None:
    		return False
    	if s.val != t.val:
    		return False

    	return self.isIdentical(s.left, t.left) and self.isIdentical(s.right, t.right)