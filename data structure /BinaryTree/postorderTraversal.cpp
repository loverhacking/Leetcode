// 二叉树的后序遍历 (来源： 牛客 BM25)
// 描述: 给定一个二叉树，返回他的后序遍历的序列。
// 后序遍历是值按照 左节点->右节点->根节点 的顺序的遍历。
// 数据范围：二叉树的节点数量满足 1≤n≤100  ，二叉树节点的值满足 1≤val≤100，树的各节点的值各不相同


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
     * @return int整型vector
     */
    vector<int> postorderTraversal(TreeNode* root) {
        // write code here
        vector<int> v;
        if (!root) return v;
        addVal(v, root);
        return v;
    }

    void addVal(vector<int>& v, TreeNode* node) {
        if (!node) return;
        addVal(v, node->left);
        addVal(v, node->right);
        v.push_back(node->val);
    }

    // 非递归版本
    /*
    vector<int> postorderTraversal(TreeNode* root) {
        // write code here
        vector<int> v;
        if (!root) return v;
        stack<TreeNode*> stk;
        TreeNode* prev = nullptr;
        TreeNode* cur = root;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }

            TreeNode* node = stk.top();
            // 需要记录上一个访问的节点，避免重复访问右子树
            // in case   1 (right)-> 3
            if (node->right && node->right != prev) {
                cur = node->right; // 如果右子树存在且没有被访问过, 转向右节点
            } else {
                v.push_back(node->val); // 访问该节点
                stk.pop();
                prev = node;
            }
        }
        return v;
    }*/
};