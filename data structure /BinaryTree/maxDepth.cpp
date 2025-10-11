// 二叉树的最大深度（来源： 牛客 BM28）
// 描述: 求给定二叉树的最大深度，
// 深度是指树的根节点到任一叶子节点路径上节点的数量。
// 最大深度是所有叶子节点的深度的最大值。
// 数据范围：0≤n≤100000，树上每个节点的val满足 ∣val∣≤100
// 要求： 空间复杂度 O(1),时间复杂度 O(n)

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型
     */
    int maxDepth(TreeNode* root) {
        // write code here
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    /* 非递归版本
    int maxDepth(TreeNode* root) {
        // write code here
        if (!root) return 0;
        queue<TreeNode*> queue;
        queue.push(root);
        int deepth = 0;
        while (!queue.empty()) {
            const int levelSize = queue.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
            deepth++;
        }
        return deepth;
    }*/


};

