// 二叉树的中序遍历 （来源：牛客 BM24）
// 描述: 给定一个二叉树的根节点root，返回它的中序遍历结果。
// 数据范围：树上节点数满足 0≤n≤1000，树上每个节点的值满足 −1000≤val≤1000
// 进阶：空间复杂度 O(n)，时间复杂度 O(n)

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型vector
     */
    vector<int> inorderTraversal(TreeNode* root) {
        // write code here
        vector<int> v;
        if (!root) return v;
        addVal(v, root);
        return v;
    }

    void addVal(vector<int>& v, const TreeNode* node) {
        if (!node) return;
        addVal(v, node->left);
        v.push_back(node->val);
        addVal(v, node->right);
    }

    // 非递归版本
    vector<int> inorderTraversal(TreeNode* root) {
        // write code here
        vector<int> v;
        if (!root) return v;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur || !stk.empty()) { // 终止条件是"当前节点为空且栈为空" in case (4 -> [# 3])
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            v.push_back(cur->val);
            cur = cur->right;
        }
        return v;
    }
};