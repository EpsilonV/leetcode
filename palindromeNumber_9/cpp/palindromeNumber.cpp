#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
        	return false;

        int revertedNumber = 0;
        while (x > revertedNumber) {
        	revertedNumber = revertedNumber * 10 + x % 10;
        	x = x / 10;
        }

        return x == revertedNumber || x == revertedNumber/10;
    }
};


int main() {
	Solution s = Solution();
	cout << s.isPalindrome(121) << endl;
	cout << s.isPalindrome(12) << endl;
	cout << s.isPalindrome(-121) << endl;

	return 0;
}