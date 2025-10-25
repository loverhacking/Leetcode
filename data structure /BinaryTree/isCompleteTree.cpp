// 判断是不是完全二叉树 (来源： 牛客 BM35）
// 描述: 给定一个二叉树，确定他是否是一个完全二叉树。
// 完全二叉树的定义：若二叉树的深度为 h，除第 h 层外，其它各层的结点数都达到最大个数，
// 第 h 层所有的叶子结点都连续集中在最左边，这就是完全二叉树。（第 h 层可能包含 [1~2h] 个节点）

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
     * @param root TreeNode类
     * @return bool布尔型
     */
    bool isCompleteTree(TreeNode* root) {
        // write code here
        deque<TreeNode*> deq;
        deq.push_back(root);

        bool isPrevNull = false;

        while (!deq.empty()) {
            TreeNode* node = deq.front();
            deq.pop_front();
            if (!node) {
                isPrevNull = true;
                continue;
            }
            if (isPrevNull) return false; // 左空右不为空，则不是完全二叉树
            deq.push_back(node->left);
            deq.push_back(node->right);
        }
        return true;
    }
};
