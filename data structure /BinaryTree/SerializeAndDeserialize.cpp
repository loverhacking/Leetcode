// 序列化二叉树(来源：牛客 BM39)
// 描述： 请实现两个函数，分别用来序列化和反序列化二叉树，不对序列化之后的字符串进行约束，但要求能够根据序列化之后的字符串重新构造出一棵与原二叉树相同的树。
// 二叉树的序列化(Serialize)是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，从而使得内存中建立起来的二叉树可以持久保存。
// 序列化可以基于先序、中序、后序、层序的二叉树等遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#）
// 二叉树的反序列化(Deserialize)是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
#include <cstdlib>
#include <deque>
#include <sstream>
class Solution {
public:
    char* Serialize(TreeNode* root) {
        stringstream ss;

        deque<TreeNode*> deq;
        if (!root) {
            ss << "# ";
        } else {
            deq.push_back(root);
            while (!deq.empty()) {
                TreeNode* node = deq.front();
                deq.pop_front();
                if (!node) {
                    ss << "# "; // 空节点用'#' 代替
                    continue;
                }
                ss << node->val << " "; // 节点之间用空格分割
                deq.push_back(node->left);
                deq.push_back(node->right);
            }
        }

        string s = ss.str();
        char* c = new char[s.size() + 1];
        strcpy(c, s.c_str());
        return c;
    }

    TreeNode* Deserialize(char* str) {
        if (str[0] == '#') return nullptr;
        string s(str);
        stringstream ss(s);
        string token;
        ss >> token;
        TreeNode* root = new TreeNode(stoi(token));
        deque<TreeNode*> deq;
        deq.push_back(root);

        while (!deq.empty()) {
            TreeNode* node = deq.front();
            deq.pop_front();

            // 构建左节点
            if (ss >> token) {
                if (token[0] != '#') {
                    node->left = new TreeNode(stoi(token));
                    deq.push_back(node->left);
                }
            }

            // 构建右节点
            if (ss >> token) {
                if (token[0] != '#') {
                    node->right = new TreeNode(stoi(token));
                    deq.push_back(node->right);
                }
            }

        }
        return root;
    }
};