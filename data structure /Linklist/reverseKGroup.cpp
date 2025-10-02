// 链表中的节点每k个一组翻转(来源： 牛客 BM3)
// 描述:将给出的链表中的节点每 k 个一组翻转，返回翻转后的链表, 如果链表中的节点数不是 k 的倍数，将最后剩下的节点保持原样
// 要求空间复杂度 O(1)，时间复杂度 O(n)
// 数据范围： 链表长度 0 <= size <= 2000, 1 <= k <= 2000, 链表中每个节点的值满足|val| <= 1000


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
     * @param k int整型
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        if (!head || !head->next || k == 1) return head;
        int len = 0;
        for (ListNode* node = head; node != nullptr;node = node->next) {
            len++;
        }

        ListNode* sentinel = new ListNode(-1);
        sentinel->next = head;

        ListNode* prev = head;
        ListNode* cur = head->next;
        ListNode* next;
        ListNode* start = head; // 翻转前该组的头节点
        ListNode* prevEnd = sentinel; // 上一组的尾节点
        for (int i = 0; i < len / k; i++) {
            for (int j = 1; j < k; j++) {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            // 经历该组翻转之后
            // prev: 该组的头节点
            // cur: 下一组翻转前的头节点
            // start: 该组的尾节点

            prevEnd->next = prev;
            prevEnd = start;

            start->next = cur;
            start = cur;

            // 移动到下一组
            prev = cur;
            cur = cur->next;
        }
        return sentinel->next;
    }
};