# 001. 两数之和

# 描述

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

    给定 nums = [2, 7, 11, 15], target = 9
    
    因为 nums[0] + nums[1] = 2 + 7 = 9
    所以返回 [0, 1]

# 想法

1. 暴力解法, 时间复杂度O(n^2), 空间复杂度O(1).
```c++
    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
        	vector<int> res;
            for (int i = 0; i < nums.size() - 1; i++) {
            	for (j = i; j < nums.size(); ++j) {
            		if (nums[i] + nums[j] == target)
            		{
            			res.push_back(i);
            			res.push_back(j);
            			return res;
            		}
            	}
            }
    
            return res;
        }
    };
```
2. 两遍哈希表, 将值nums[i]和index i作为键和值存入哈希表，第二遍循环，在hash表里寻找target-nums[i]. 时间复杂度O(n), 空间复杂度O(n).
```c++
    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int, int> mapping;
        	vector<int> res;
            for (int i = 0; i < nums.size(); i++) {
                mapping[nums[i]] = i;
            }
            for (int i = 0; i < nums.size(); i++) {
                if (mapping.find(target-nums[i]) != mapping.end()){
                    res.push_back(i);
                    res.push_back(mapping[target-nums[i]]);
                    return res;
                }
            }
    
            return res;
        }
    };
```
3. 一次哈希表. 时间复杂度O(n), 空间复杂度O(n).
```c++
    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int, int> mapping;
        	vector<int> res;
            for (int i = 0; i < nums.size(); i++) {
                if (mapping.find(target-nums[i]) != mapping.end()){
                    res.push_back(i);
                    res.push_back(mapping[target-nums[i]]);
                    return res;
                }
                mapping[nums[i]] = i;
            }
    
            return res;
        }
    };
```