#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        _nums.assign(nums.begin(), nums.end());
    }

    void update(int index, int val) {
        _nums[index] = val;
    }

    int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; i++) {
            sum += _nums[i];
        }

        return sum;
    }

private:
    vector<int> _nums;
};

int main() {
    vector<int> v1 = {1,3,5};
    NumArray numarray(v1);
    cout << numarray.sumRange(0, 2) << endl;
    numarray.update(1, 2);
    cout << numarray.sumRange(0, 2) << endl;
    return 0;
}


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */