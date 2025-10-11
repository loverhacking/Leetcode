// 二叉树的前序遍历 （来源：牛客 BM23）
// 描述: 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
// 数据范围：二叉树的节点数量满足 1≤n≤100  ，二叉树节点的值满足 1≤val≤100  ，树的各节点的值各不相同

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
    vector<int> preorderTraversal(TreeNode* root) {
        // write code here
        vector<int> v;
        addVal(root, v);
        return v;
    }

    void addVal(TreeNode* node, vector<int>& v) {
        if (!node) return;
        v.push_back(node->val);
        addVal(node->left, v);
        addVal(node->right, v);
    }

    // 非递归版本 （用栈模拟）
    /*
    vector<int> preorderTraversal(TreeNode* root) {
        // write code here
        vector<int> v;
        if (!root) return v;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            v.push_back(node->val);

            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
        }
        return v;
    }
    */


};