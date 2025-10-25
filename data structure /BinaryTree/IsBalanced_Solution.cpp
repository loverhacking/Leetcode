// 判断是不是平衡二叉树 (来源： 牛客 BM36）
// 描述: 输入一棵节点数为 n 二叉树，判断该二叉树是否是平衡二叉树。
// 在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树
// 平衡二叉树（Balanced Binary Tree），具有以下性质：
// 它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。

/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
#include <algorithm>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pRoot TreeNode类
     * @return bool布尔型
     */
    bool IsBalanced_Solution(TreeNode* pRoot) {
        // write code here
        return IsBalanced_SolutionHelper(pRoot) != -1;
    }
private:
    int IsBalanced_SolutionHelper(TreeNode* root) {
        // 采用后序遍历 由下而上
        // 函数实际返回节点所在的高度
        // 如果不是平衡二叉树，则返回特殊值 -1
        if (!root) return 0;
        int left = IsBalanced_SolutionHelper(root->left);
        if (left == -1) return -1;
        int right = IsBalanced_SolutionHelper(root->right);
        if (right == -1) return -1;
        if (abs(left - right) > 1) return -1;
        return 1 + max(left, right);
    }
};