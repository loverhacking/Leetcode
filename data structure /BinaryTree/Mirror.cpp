// 二叉树的镜像 (来源： 牛客 BM33）
// 操作给定的二叉树，将其变换为源二叉树的镜像。
// 数据范围：二叉树的节点数 0≤n≤1000 ， 二叉树每个节点的值 0≤val≤1000
// 要求： 空间复杂度 O(n) 。本题也有原地操作，即空间复杂度 O(1) 的解法，时间复杂度 O(n)

/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pRoot TreeNode类
     * @return TreeNode类
     */
    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
        if (!pRoot) return pRoot;
        TreeNode* left = Mirror(pRoot->left);
        TreeNode* right = Mirror(pRoot->right);
        pRoot->left = right;
        pRoot->right = left;
        return pRoot;
    }

    /* 非递归写法
    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
        if (!pRoot) return pRoot;
        stack<TreeNode*> stk;
        stk.push(pRoot);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            if (node->left) stk.push(node->left);
            if (node->right) stk.push(node->right);
            // swap
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
        return pRoot;
    }*/
};

