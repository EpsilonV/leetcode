class Solution:
    def subarraySum(self, nums, k):
        if len(nums) == 0:
            return 0
        prevSum = 0
        d = {0:1}
        count = 0
        for i in range(len(nums)):
            prevSum += nums[i]
            if (d.get(prevSum - k)):
                count += d[prevSum-k]

            if d.get(prevSum):
                d[prevSum] += 1
            else:
                d[prevSum] = 1

        return count
