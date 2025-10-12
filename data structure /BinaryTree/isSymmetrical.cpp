// 对称的二叉树 （来源： 牛客 BM31）
// 描述: 给定一棵二叉树，判断其是否是自身的镜像（即：是否对称）
// 数据范围：节点数满足 0≤n≤1000，节点上的值满足 ∣val∣≤1000
// 要求：空间复杂度 O(n)，时间复杂度 O(n)

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
     * @param pRoot TreeNode类
     * @return bool布尔型
     */
    bool isSymmetrical(TreeNode* pRoot) {
        // write code here
        if(!pRoot) return true;

        deque<TreeNode*> deq;
        deq.push_back(pRoot->left);
        deq.push_back(pRoot->right);
        while(!deq.empty()) {
            // 每次取出两个节点
            TreeNode* left = deq.front();
            deq.pop_front();
            TreeNode* right = deq.front();
            deq.pop_front();
            if (!left && !right) continue; // 两个节点都为空，继续检查下一对
            if (!left || !right) return false; // 1个节点为空，另一个不为空
            if (left->val != right->val) return false;
            // 按对称位置入队：左左 vs 右右，左右 vs 右左
            deq.push_back(left->left);
            deq.push_back(right->right);
            deq.push_back(left->right);
            deq.push_back(right->left);
        }
        return true;
    }

    /* 递归写法
    bool isSymmetrical(TreeNode* pRoot) {
        // write code here
        if (!pRoot) return true;
        return isSymmetricalHelper(pRoot->left, pRoot->right);
    }
    */

    bool isSymmetricalHelper(TreeNode* left, TreeNode* right) {
        // 两个节点都为空
        if (!left && !right) return true;
        if (!left || !right) return false;
        // 一个为空，一个不为空
        if (left->val != right->val) return false;
        // 递归检查：左子树的左节点 vs 右子树的右节点
        // 左子树的右节点 vs 右子树的左节点
        return isSymmetricalHelper(left->left, right->right) &&
            isSymmetricalHelper(left->right, right->left);
    }


};
