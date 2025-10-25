// 合并二叉树 (来源： 牛客 BM32）
// 描述： 已知两颗二叉树，将它们合并成一颗二叉树。
// 合并规则是：都存在的结点，就将结点值加起来，否则空的位置就由另一个树的结点来代替。
// 数据范围：树上节点数量满足 0≤n≤500，树上节点的值一定在32位整型范围内。
// 空间复杂度 O(1) ，时间复杂度 O(n)

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
     * @param t1 TreeNode类
     * @param t2 TreeNode类
     * @return TreeNode类
     */
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // write code here
        if (!t1) return t2;
        if (!t2) return t1;
        t1->val = t1->val + t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }

    /* 非递归写法
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // write code here
        if (!t1) return t2;
        if (!t2) return t1;
        stack<pair<TreeNode*, TreeNode*>> stk;
        stk.push({t1, t2});

        while (!stk.empty()) {
            auto [t1, t2] = stk.top();
            stk.pop();
            t1->val = t1->val + t2->val;
            // 如果两棵树都有左子树，入栈继续处理
            if (t1->left && t2->left) {
                stk.push({t1->left, t2->left});
            }
            // 如果只有t2有左子树，直接连接到t1
            if (!t1->left && t2->left) {
                t1->left = t2->left;
            }
            // 如果只有t1有左子树或都没有，不需要额外操作

            // 如果两棵树都有右子树，入栈继续处理
            if (t1->right && t2->right) {
                stk.push({t1->right, t2->right});
            }

            // 如果只有t2有右子树，直接连接到t1
            if (!t1->right && t2->right) {
                t1->right = t2->right;
            }

            // 如果只有t1有右子树或都没有，不需要额外操作

        }
        return t1;
    }*/
};