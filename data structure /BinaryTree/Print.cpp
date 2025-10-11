// 按之字形顺序打印二叉树(来源： 牛客 BM27)
// 描述: 给定一个二叉树，返回该二叉树的之字形层序遍历，（第一层从左向右，下一层从右向左，一直这样交替）
// 数据范围：0≤n≤1500,树上每个节点的val满足 ∣val∣<=1500
// 空间复杂度：O(n)，时间复杂度：O(n)


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
     * @param pRoot TreeNode类
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > Print(TreeNode* pRoot) {
        // write code here
        vector<vector<int>> v;
        if (!pRoot) return v;
        deque<TreeNode*> deq;
        bool leftToRight = true;  // 当前层遍历方向
        deq.push_back(pRoot);
        while (!deq.empty()) {
            int levelSize = deq.size();
            vector<int> curLevel;
            if (leftToRight) {
                // 当前层从左向右
                // 则遍历时在尾部弹出节点，在头部插入新的子节点 3 2
                for (int i = 0; i < levelSize; i++) {
                    TreeNode* node = deq.back();
                    deq.pop_back();
                    curLevel.push_back(node->val);
                    if (node->left) deq.push_front(node->left);
                    if (node->right) deq.push_front(node->right);
                }

            } else {
                // 当前层从右向左
                // 则遍历时在头部弹出节点，在尾部插入新的子节点 5 4
                // 注意插入子节点是先右后左，则弹出时变成先左后右
                for (int i = 0; i < levelSize; i++) {
                    TreeNode* node = deq.front();
                    deq.pop_front();
                    curLevel.push_back(node->val);
                    if (node->right) deq.push_back(node->right);
                    if (node->left) deq.push_back(node->left);
                }
            }
            leftToRight = !leftToRight;
            v.push_back(curLevel);
        }
        return v;

    }
};