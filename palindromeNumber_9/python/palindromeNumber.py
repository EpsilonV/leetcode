class Solution:
	#将 参数x 转换成string
    def isPalindrome1(self, x: int) -> bool:
        sx = str(x)
        for i in range(len(sx)//2):
        	if sx[i] != sx[-i-1]:
        		return False

        return True
    #1. 参数为负数时，直接返回False
    #2. 计算正数的倒叙值，若为回文数，则倒叙值和原值相同
    def isPalindrome2(self, x: int) -> bool:
    	if x < 0:
    		return False
    	postx = 0
    	num = x
    	while num:
    		postx = postx *10 + num % 10
    		num = num // 10

    	return x == postx

if __name__ == '__main__':
	s = Solution()
	assert(s.isPalindrome1(121)==True)
	assert(s.isPalindrome1(12)==False)
	assert(s.isPalindrome1(-121)==False)

	assert(s.isPalindrome2(121)==True)
	assert(s.isPalindrome2(12)==False)
	assert(s.isPalindrome2(-121)==False)
