// 在二叉树中找到两个节点的最近公共祖先 (来源：牛客 BM38）
// 描述：给定一棵二叉树(保证非空)以及这棵树上的两个节点对应的val值 o1 和 o2，请找到 o1 和 o2 的最近公共祖先节点。
// 数据范围：树上节点数满足 1≤n≤10^5, 节点值val满足区间 [0,n)
// 注：本题保证二叉树中每个节点的val值均不相同。
// 要求：时间复杂度 O(n)

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
     * @param o1 int整型
     * @param o2 int整型
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        if (!root) return -1;
        if (o1 == root->val || o2 == root->va) return root->val; //节点为其中一个
        int left = lowestCommonAncestor(root->left, o1, o2);
        int right = lowestCommonAncestor(root->right, o1, o2);
        if (left == -1) return right; // 此时两个节点都在右侧
        if (right == -1) return left; // 此时两个节点都在左侧
        return root->val; // 此时两个节点分别位于左右两侧

    }
};


// 递归情况：
// 1.当到达空节点（既叶子节点的子节点）时，直接返回空
// 2.当root等于 o1 或 o2 时，返回root
// 3.若不为1， 2中情况，说明需要继续处理：
//    对左子树进行递归，返回值记为 t1
//    对右子树进行递归，返回值记位 t2
// t1 ，t2 存在以下几种情况：
// ①. 当t1, t2都为空时，说明root的左右子树中都不存在o1, o2， 返回空
// ②. 当t1为空且t2不为空时，说明左子树找不到 o1, o2,所以返回 t2
// ③. 当t2为空且t1不为空时，说明右子树找不到 o1, o2,所以返回 t1
// ④. 当t1, t2都不为空时,说明o1, o2分别位于root的左右子树中，既root为答案，返回root