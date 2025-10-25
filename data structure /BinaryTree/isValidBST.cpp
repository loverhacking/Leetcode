// 判断是不是二叉搜索树 (来源： 牛客 BM34）
// 描述: 给定一个二叉树根节点，请你判断这棵树是不是二叉搜索树。
// 二叉搜索树满足每个节点的左子树上的所有节点均小于当前节点且右子树上的所有节点均大于当前节点。

/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
#include <climits>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return bool布尔型
     */
    bool isValidBST(TreeNode* root) {
        // write code here
        if (!root) return true;
        // 对BST采用前序遍历，可以得到递增序列
        // 因此，仅需判断前节点和当前节点满足递增关系就可
        if (!isValidBST(root->left)) return false;
        if (prev >= root->val) {
            return false;
        } else {
            prev = root->val;
        }
        if (!isValidBST(root->right)) return false;
        return true;

    }

    /* 非递归写法
    bool isValidBST(TreeNode* root) {
        // write code here
        if (!root) return true;
        TreeNode* cur = root;
        stack<TreeNode*> stk;
        while (cur || !stk.empty()) {
            // 遍历到最左节点
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }

            // 处理当前节点
            cur = stk.top();
            stk.pop();

            // 检查是否满足递增序列
            if (prev >= cur->val) return false;
            prev = cur->val;

            // 转向右子树
            cur = cur->right;
        }
        return true;
    }*/


private:
    int prev = INT_MIN;
};