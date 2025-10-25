// 重建二叉树(来源： 牛客 BM40)
// 描述: 给定节点数为 n 的二叉树的前序遍历和中序遍历结果，请重建出该二叉树并返回它的头结点。
//提示: 1.vin.length == pre.length
// 2.pre 和 vin 均无重复元素
// 3.vin出现的元素均出现在 pre里
// 4.只需要返回根结点
// 数据范围：n≤2000，节点的值
// 要求：空间复杂度 O(n)，时间复杂度 O(n)

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
     * @param preOrder int整型vector
     * @param vinOrder int整型vector
     * @return TreeNode类
     */
    TreeNode* reConstructBinaryTree(vector<int>& preOrder, vector<int>& vinOrder) {
        // write code here
        for (int i = 0; i < vinOrder.size(); i++) {
            indexVin[vinOrder[i]] = i; // 构建中序遍历值与下标的映射
        }
        return buildTree(preOrder, vinOrder, 0, preOrder.size() - 1, 0,
                         vinOrder.size() - 1);

    }
private:
    unordered_map<int, int> indexVin;
    TreeNode* buildTree(vector<int>& preOrder, vector<int>& vinOrder, int preStart, int preEnd, int vinStart, int vinEnd) {
        if (preStart > preEnd) return nullptr;
        int rootVal = preOrder[preStart]; // 前序遍历第一位为根节点
        TreeNode* root = new TreeNode(rootVal);
        int rootIndex = indexVin[rootVal]; // 根节点下标
        int size = rootIndex - vinStart; // 左子树的长度
        // 在前序遍历中：左子树：[preStart + 1, preStart + size], 中序遍历中，左子树：[vinStart, rootIndex - 1]
        root->left = buildTree(preOrder, vinOrder, preStart + 1, preStart + size, vinStart, rootIndex - 1);
        // 在前序遍历中：右子树：[preStart + size + 1, preEnd], 中序遍历中，右子树：[rootIndex + 1, vinEnd]
        root->right = buildTree(preOrder, vinOrder, preStart + size + 1, preEnd, rootIndex + 1, vinEnd);
        return root;

    }

};
