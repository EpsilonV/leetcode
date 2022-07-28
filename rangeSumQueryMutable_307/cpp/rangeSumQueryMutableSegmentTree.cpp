#include <iostream>
#include <vector>

using namespace std;

struct SegmentTreeNode {
    int _start, _end, _val;
    SegmentTreeNode *_left, *_right;
    SegmentTreeNode(int start, int end, int val=0) {
        _start = start,
        _end = end;
        _val = val;
        _left = nullptr;
        _right = nullptr;
    }
};

class NumArray {
public:
    SegmentTreeNode *_root;
    int numsSize = 0;

    SegmentTreeNode* buildTree(vector<int> nums, int left, int right) {
        if (left == right) {
            SegmentTreeNode *_node = new SegmentTreeNode(left, right, nums[left]);
            return _node;
        }
        int mid = left + (right - left) / 2;
        SegmentTreeNode *_node = new SegmentTreeNode(left, right);
        _node->_left = buildTree(nums, left, mid);
        _node->_right = buildTree(nums, mid+1, right);
        _node->_val = _node->_left->_val + _node->_right->_val;
        return _node;
    }

    int updateNode(SegmentTreeNode *root,  int left, int right, int index, int val) {
        if (root->_start == root->_end && root->_start == index) {
            int delta = val - root->_val;
            root->_val = val;
            return delta;
        }
        int mid = left + (right - left) / 2;
        if (index <= mid) {
            int delta = updateNode(root->_left, left, mid, index, val);
            root->_val += delta;
            return delta;
        }else {
            int delta = updateNode(root->_right, mid+1, right, index, val);
            root->_val += delta;
            return delta;
        }
        return 0;
    }

    NumArray(vector<int>& nums) {
        _root = buildTree(nums, 0, nums.size()-1);
        numsSize = nums.size() - 1;
    }

    void update(int index, int val) {
        updateNode(_root, 0, numsSize, index, val);
    }

    int nodeSumRange(SegmentTreeNode *root, int left, int right) {
        if (root->_start == left && root->_end == right) {
            return root->_val;
        }
        int mid = root->_start + (root->_end - root->_start)/2;
        if (right <= mid) {
            return nodeSumRange(root->_left, left, right);
        }else if (left > mid) {
            return nodeSumRange(root->_right, left, right);
        }else {
            int leftVal =  nodeSumRange(root->_left, left, mid);
            int rightVal = nodeSumRange(root->_right, mid+1, right);
            return leftVal + rightVal;
        }
    }

    int sumRange(int left, int right) {
        return nodeSumRange(_root, left, right);
    }
};

int main() {
    vector<int> v1 = {1,3,5};
    NumArray numarray(v1);
    cout << numarray.sumRange(0, 2) << endl;
    numarray.update(1, 4);
    cout << numarray.sumRange(0, 2) << endl;
    return 0;
}