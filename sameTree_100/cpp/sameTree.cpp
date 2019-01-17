/*
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
*/

using namespace std;

//递归法
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;
    if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
        return false;
		if (q->val != p->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

//迭代法 BFS
bool isSameTree(TreeNode* p, TreeNode* q) {
    list<TreeNode*> queueP;
    list<TreeNode*> queueQ;

    TreeNode  *nodeP(0), *nodeQ(0);

    if (p != NULL)
      queueP.push_back(p);
    if (q != NULL)
      queueQ.push_back(q);

    while (!queueP.empty() && !queueQ.empty()) {
      nodeP = queueP.front();
      nodeQ = queueQ.front();
      if (nodeP->val != nodeQ->val) {
        return false;
      }
      queueP.pop_front();
      queueQ.pop_front();

      if (nodeP->left != NULL && nodeQ->left == NULL)
        return false;
      if (nodeP->left == NULL && nodeQ->left != NULL)
        return false;
      if (nodeP->left != NULL && nodeQ->left != NULL) {
        queueP.push_back(nodeP->left);
        queueQ.push_back(nodeQ->left);
      }
      if (nodeP->right != NULL && nodeQ->right == NULL)
        return false;
      if (nodeP->right == NULL && nodeQ->right != NULL)
        return false;
      if (nodeP->right != NULL && nodeQ->right != NULL) {
        queueP.push_back(nodeP->right);
        queueQ.push_back(nodeQ->right);
      }
    }

    if (queueP.empty() && queueQ.empty()) {
      return true;
    }

    return false;
}
