// 删除有序链表中重复的元素-II
// 描述: 给出一个升序排序的链表，删除链表中的所有重复出现的元素，只保留原链表中只出现一次的元素
// 数据范围：链表长度 0≤n≤10000，链表中的值满足 ∣val∣≤1000
// 要求：空间复杂度 O(1)，时间复杂度 O(n)

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
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode* deleteDuplicates2(ListNode* head) {
        // write code here
        if (!head || !head->next) return head;
        ListNode* sentinel = new ListNode(-1);
        sentinel->next = head;
        ListNode* prev = sentinel;
        ListNode* cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                int v = cur->val;
                while (cur->val == v) {
                    cur = cur->next;
                    if (!cur) break;
                }
                prev->next = cur;
            } else {
                prev = prev->next;
                cur = cur->next;
            }
        }
        return sentinel->next;
    }
};