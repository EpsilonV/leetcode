class Solution:
    def massage(self, nums):
    	if len(nums) == 0:
    		return 0
    	if len(nums) == 1:
    		return nums[0]
    	a = nums[0]
    	b = max(nums[0], nums[1])
    	c = b
    	for i in range(2, len(nums)):
    		c = max(b, a + nums[i])
    		b,a = c,b

    	return c