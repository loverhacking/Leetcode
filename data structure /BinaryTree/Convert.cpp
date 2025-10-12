// 二叉搜索树与双向链表 (来源： 牛客 BM30)
// 描述: 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表
//    10
//  6    14      ====> 4 <-> 6 <-> 8 <-> 10 <-> 12 <-> 14 <-> 16
// 4 8  12 16
// 数据范围：输入二叉树的节点数 0≤n≤1000，二叉树中每个节点的值 0≤val≤1000
// 要求：空间复杂度 O(1)（即在原树上操作），时间复杂度 O(n)
// 注意:
// 1.要求不能创建任何新的结点，只能调整树中结点指针的指向。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继
// 2.返回链表中的第一个节点的指针
// 3.函数返回的TreeNode，有左右指针，其实可以看成一个双向链表的数据结构

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (!pRootOfTree) return nullptr;
        TreeNode* prev = nullptr;
        convertHelper(pRootOfTree, prev);
        TreeNode* head = pRootOfTree;
        //  找到链表的头节点（最左边的节点）
        while (head->left) head = head->left;
        return head;
    }
private:
    // prev: 通过指针的引用传递, 否则在递归调用中对prev的修改不会影响上一层
    void convertHelper(TreeNode* root, TreeNode*& prev) {
        if(!root) return;
        // 1. 递归处理左子树
        convertHelper(root->left, prev);
        // 2. 处理当前节点
        // 将当前节点的左指针指向前驱节点
        root->left = prev;
        // 如果前驱节点存在，将前驱节点的右指针指向当前节点
        if (prev) prev->right = root;
        // 更新前驱节点为当前节点
        prev = root;
        // 3. 递归处理右子树
        convertHelper(root->right, prev);
    }
};
