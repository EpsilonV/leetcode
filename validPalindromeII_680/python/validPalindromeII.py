class Solution:
	def validPalindrome(self, s):
		low, high = 0, len(s)-1
		while low < high:
			if s[low] == s[high]:
				low += 1
				high -= 1
			else:
				return self.helper(s, low+1, high) or self.helper(s, low, high-1)
		return True

	def helper(self, s, low, high):
		while low < high:
			if s[low] == s[high]:
				low += 1
				high -= 1
			else:
				return False

		return True
		

if __name__ == '__main__':
	s = Solution()
	print(s.validPalindrome("abca"))
	print(s.validPalindrome("aba"))
	print(s.validPalindrome("abc"))
	print(s.validPalindrome("abcghhgfcba"))
	print(s.validPalindrome("abcghvhgcban"))
	print(s.validPalindrome("a"))
	print(s.validPalindrome("ab"))
	print(s.validPalindrome("abbbbbba"))
	print(s.validPalindrome(""))