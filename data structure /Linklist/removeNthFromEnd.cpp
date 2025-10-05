// 删除链表的倒数第n个节点(来源：牛客 BM9)
// 描述给定一个链表，删除链表的倒数第 n 个节点并返回链表的头指针
// 数据范围： 链表长度 0≤n≤1000，链表中任意节点的值满足 0≤val≤100
// 要求：空间复杂度 O(1)，时间复杂度 O(n)
// 备注：题目保证 n 一定是有效的

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
     * @param n int整型
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // write code here
        if (!head || n == 0) return head;
        ListNode* sentinel = new ListNode(-1);
        sentinel->next = head;
        ListNode* fast = head;
        for (int i = 1; i <= n - 1; i++) {
            fast = fast->next;
        }
        ListNode* slow = sentinel;
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return sentinel->next;
    }
};