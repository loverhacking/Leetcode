// 合并两个排序的链表(来源： 牛客 BM4)
// 描述: 输入两个递增的链表，单个链表的长度为n，合并这两个链表并使新链表中的节点仍然是递增排序的。
// 数据范围： 0 <= n <= 1000, −1000 <= 节点值 <= 1000
// 要求：空间复杂度 O(1), 时间复杂度 O(n)

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <ratio>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pHead1 ListNode类
     * @param pHead2 ListNode类
     * @return ListNode类
     */
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        // write code here
        if (!pHead1) return pHead2;
        if (!pHead2) return pHead1;
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        ListNode* sentinel = new ListNode(-1);
        sentinel->next = pHead2;
        ListNode* prev = sentinel; // p2的前节点
        // 将节点全部合并到p2上
        while (p1 && p2) {
            if (p1->val > p2->val) {
                p2 = p2->next;
                prev = prev->next;
            } else {
                ListNode* temp = p1->next;
                p1->next = p2;
                prev->next = p1;
                p1 = temp;
                prev = prev->next; // 注意因为插入p1节点，prev必须前进一步才是p2的前节点
            }
        }
        // 如果p1不空
        if (p1) {
            prev->next = p1;
        }
        return sentinel->next;
    }

    // 递归
    /*
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        // write code here
        if (!pHead1) return pHead2;
        if (!pHead2) return pHead1;
        if (pHead1->val > pHead2->val) {
            pHead2->next = Merge(pHead1, pHead2->next);
            return pHead2;
        } else {
            pHead1->next = Merge(pHead1->next, pHead2);
            return pHead1;
        }
    }
    */
};