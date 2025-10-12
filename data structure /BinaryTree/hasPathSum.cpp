// 二叉树中和为某一值的路径(一)  （来源： 牛客 BM29）
// 描述: 给定一个二叉树root和一个值 sum ，判断是否有从根节点到叶子节点的节点值之和等于 sum 的路径。
// 该题路径定义为从树的根结点开始往下一直到叶子结点所经过的结点
// 叶子节点是指没有子节点的节点
// 路径只能从父节点到子节点，不能从子节点到父节点
// 总节点数目为n
//数据范围：树上的节点数满足 0≤n≤10000
// 每 个节点的值都满足 ∣val∣≤1000
// 要求：空间复杂度 O(n)，时间复杂度 O(n)
 //进阶：空间复杂度 O(树的高度)，时间复杂度 O(n)

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
     * @param sum int整型
     * @return bool布尔型
     */
    bool hasPathSum(TreeNode* root, int sum) {
        // write code here
        if (!root) return false;
        if (sum == root->val && isLeaf(root)) return true;
        return hasPathSum(root->left, sum - root->val) ||
            hasPathSum(root->right, sum - root->val);
    }

    /* 非递归写法
    bool hasPathSum(TreeNode* root, int sum) {
        // write code here
        if (!root) return false;
        stack<TreeNode*> stk;
        stack<int> val;
        stk.push(root);
        val.push(sum);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            int curSum = val.top();
            val.pop();
            if (isLeaf(node) && curSum == node->val) return true;
            if (node->left) {
                stk.push(node->left);
                val.push(curSum - node->val);
            }
            if (node->right) {
                stk.push(node->right);
                val.push(curSum - node->val);
            }
        }
        return false;
    }
    */

    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }
};