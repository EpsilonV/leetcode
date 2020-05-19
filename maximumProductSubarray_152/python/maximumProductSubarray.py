class Solution:
	def maxProduct(self, nums):
		maxF = nums[:]
		minF = nums[:]

		for i in range(1, len(nums)):
			maxF[i] = max(maxF[i-1]*nums[i], max(nums[i], minF[i-1] * nums[i]))
			minF[i] = min(minF[i-1]*nums[i], min(nums[i], maxF[i-1] * nums[i]))

		return max(maxF)


s = Solution()
print(s.maxProduct([2,3,-2,4,0,-2,-9,-10,9,9,0,0,0,3,4,-5,6,-7,-8]))
print(s.maxProduct([-2,0,-1]))
print(s.maxProduct([-2,0,-1,-4,9,0,8,0,0,5,6,-8]))
print(s.maxProduct([7,-2,-4]))
print(s.maxProduct([-7,2,4]))
print(s.maxProduct([2,3,-2,4]))
print(s.maxProduct([-8]))