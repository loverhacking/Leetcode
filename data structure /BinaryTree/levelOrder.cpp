// 求二叉树的层序遍历 (来源： 牛客 BM26)
// 描述: 给定一个二叉树，返回该二叉树层序遍历的结果，（从左到右，一层一层地遍历）

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
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        // write code here
        vector<vector<int>> v;
        if (!root) return v;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            vector<int> curLevel;
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                curLevel.push_back(node->val);
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
            v.push_back(curLevel);
        }
        return v;
    }

    /*
    vector<vector<int>> levelOrder(TreeNode* root) {
        // write code here
        vector<vector<int>> v;
        traverse(v, 0, root);
        return v;

    }
    */

    // 递归版本
    void traverse(vector<vector<int>>& v, int deepth, TreeNode* node) {
        if (!node) return;
        if (v.size() <= deepth) {
            v.push_back(vector<int>());
        }
        v[deepth].push_back(node->val);
        traverse(v, deepth + 1, node->left);
        traverse(v, deepth + 1, node->right);
    }
};