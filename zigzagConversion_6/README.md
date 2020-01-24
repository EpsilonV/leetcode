## 006. Z 字形变换

### 描述

将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
比如输入字符串为 `LEETCODEISHIRING` 行数为 3 时，排列如下：

```
L   C   I   R
E T O E S I I G
E   D   H   N
```
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如：`LCIRETOESIIGEDHN`。
请你实现这个将字符串进行指定行数变换的函数：

```
string convert(string s, int numRows);
```
#### 示例 1:

```
输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
```

#### 示例 2:

```
输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
```
### 想法
### 方法一：按行排序
从左向右迭代字符串，将合适的字符加到Z字图形中的每一行。根据题意，一共有min(numRows, len(s)) 行字符串，当当前行 curRow 为0时，或者 numRows - 1 时，行增长方向将翻转。

```
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
```
#### 复杂度分析
* 时间复杂度 O(n)  n为len(s)
* 空间复杂度 O(n)

### 方法二：按行访问
每一行的字符下标其实是有规律的，我们可以根据规律来访问Z字图形的每一行。假设下标间距 `step=2*numRows - 2`.
我们可以得到下面规律：

1. 每行的起始小标都是行号
2. 第 0 层和 numRows - 1 层下标的间隔都是 `step`
3. 中间层的下标都是`step - 2*行号` `2*行号` 交替

```
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
```
#### 复杂度分析
* 时间复杂度 O(n) n为len(s)
* 空间复杂度 O(n)































