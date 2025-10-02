// 链表内指定区间反转 (来源：牛客 BM2)
// 描述:将一个节点数为 size 链表 m 位置到 n 位置之间的区间反转
// 要求时间复杂度 O(n)，空间复杂度 O(1)
// 数据范围： 链表长度 0 < size <= 1000, 0 < m <= n <= size, 链表中每个节点的值满足|val| <= 1000


/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <cstdio>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        if (!head || !head -> next) return head;
        if (m == n) return head;

        // in case3->5, m = 1, n = 2
        ListNode* sentinel = new ListNode(-1);
        sentinel->next = head;

        ListNode* start = sentinel;

        for (int i = 1; i <= m - 1; i++) {
            start = start->next;
        }
        ListNode* prev = start->next;
        ListNode* cur = prev->next;
        ListNode* next;

        for (int i = 1; i <= n - m; i++) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        start->next->next = next;
        start->next = prev;
        return sentinel->next;
    }
};