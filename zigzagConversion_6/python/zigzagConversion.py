"""
方法一：按行排序
从左向右迭代字符串，将合适的字符加到Z字图形中的每一行。根据题意，一共有min(numRows, len(s)) 行字符串，当当前行 curRow 为0时，或者 numRows - 1 时，行增长方向将翻转。
"""

"""
class Solution:
    def convert(self, s: str, numRows: int) -> str:
    	if numRows <= 1:
    		return s
    	curRow = 0
    	rowStrings = ['' for i in range(min(numRows, len(s)))]
    	rowGrow = False
    	for c in s:
    		rowStrings[curRow] += c
    		if curRow == 0 or curRow == numRows-1:
    			rowGrow = not rowGrow
    		curRow += 1 if rowGrow else -1
    		print(curRow)

    	res = ''
    	for rs in rowStrings:
    		res += rs

    	return res
"""

"""
方法二：按行访问
每一行的字符下标其实是有规律的，我们可以根据规律来访问Z字图形的每一行。假设下标间距 `step=2*numRows - 2`.
我们可以得到下面规律:
1. 每行的起始小标都是行号
2. 第 0 层和 numRows - 1 层下标的间隔都是 `step`
3. 中间层的下标都是`step - 2*行号` `2*行号` 交替
”“”
"""

class Solution:
    def convert(self, s: str, numRows: int) -> str:
    	if numRows <= 1:
    		return s
    	rows = min(numRows, len(s))
    	step = 2*numRows - 2
    	res = ''
    	for row in range(rows):
    		index = row
    		curStep = row * 2
    		while (index < len(s)):
    			res += s[index]
    			curStep = step - curStep
    			index += step if (row == 0 or row == numRows - 1) else curStep

    	return res

if __name__ == '__main__':
	s = Solution()
	assert s.convert("LEETCODEISHIRING", 3)=="LCIRETOESIIGEDHN"
	assert s.convert("LEETCODEISHIRING", 4)=="LDREOEIIECIHNTSG"
	assert s.convert("LEETCODEISHIRING", 2)=="LECDIHRNETOESIIG"
	assert s.convert("LEETCODEISHIRING", 1)=="LEETCODEISHIRING"
	print("PASS")




