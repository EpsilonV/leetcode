/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

//解法1 使用暴力解法
/*
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    bool find = false;
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = i; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target){
                find = true;
                res.push_back(i);
                res.push_back(j);
                break;
            }
        }
        if (find)
            break;
    }

    return res;
}
*/

//解法2 使用Map, 将nums[i]作为key, i 作为value存放在Map中，
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    map<int, int> hash;
    for (int i = 0; i < nums.size(); i++) {
        if (hash.find(target - nums[i]) != hash.end()){
           res.push_back(hash[target - nums[i]]);
           res.push_back(i);
           break;
        }

        hash[nums[i]] = i;
    }
    
    return res;
}

int main() {
    vector<int> nums = {2,7,11,15};
    vector<int> res = twoSum(nums, 9);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}
