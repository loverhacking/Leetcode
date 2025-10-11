// 判断一个链表是否为回文结构 (来源：牛客 BM13）
// 描述: 给定一个链表，请判断该链表是否为回文结构。
// 回文是指该字符串正序逆序完全一致。
//数据范围： 链表节点数 0≤n≤10，链表中每个节点的值满足 ∣val∣≤10^7

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        // write code here
        if (!head || !head->next) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is in the middle of the list
        ListNode* first = head;
        ListNode* second = fast? slow->next : slow;
        second = reverse(second); // 后半部分翻转
        while (second) { // 这里应该用second作为循环条件
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
    }

    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* prev =nullptr;
        ListNode* cur = head;
        ListNode* next;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};