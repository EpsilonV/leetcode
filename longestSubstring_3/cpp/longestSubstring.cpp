/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 

Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include<iostream>
#include<map>
#include<vector>

using namespace std;

//解法1 使用two pointer（begin, end）去指向substring的头尾，并且使用map维护了每个字符在string中的index,
//      如果新的字符在map中存在，并且index大于start,
//      说明新的字符出现在了substrig中，需要跟新begin以及当前字符的index.
int lengthOfLongestSubstring(string s) {
    map<char, int> hash;
    int begin = 0, end = 0, maxLen = 0;
    for (end = 0; end < s.length(); end++) {
        if (hash.find(s[end]) != hash.end() && hash[s[end]] >= begin) {
            begin = hash[s[end]] + 1;
            hash[s[end]] = end;
        }else{
            hash[s[end]] = end;
        }

        if (end - begin + 1 > maxLen)
            maxLen = end - begin + 1;
    }

    return maxLen;
}

//解法2 使用vector<int> hash(256, -1)去代替map
int lengthOfLongestSubstring(string s) {
    vector<int> hash(256, -1);
    int start = -1, maxLen = 0;
    for (int i = 0; i < s.length(); i++) {
        if (hash[s[i]] > start) 
            start = hash[s[i]];
        hash[s[i]] = i;
        maxLen = max(maxLen, i - start); 
    }

    return maxLen;
}
