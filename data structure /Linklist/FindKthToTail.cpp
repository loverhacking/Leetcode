// 链表中倒数最后k个结点(来源： 牛客 BM8)
// 描述: 输入一个长度为 n 的链表，返回该链表中倒数第k个节点。
// 数据范围：0 <= n <= 10^5, 0 <= k <= 10^9
// 如果该链表长度小于k，请返回一个长度为 0 的链表。
// 空间复杂度 O(1)，时间复杂度 O(n)

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
     * @param pHead ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
        if (!pHead) return pHead;
        if (k == 0) return nullptr;
        ListNode* fast = pHead;
        for (int i = 1; i <= k - 1; i++) {
            fast = fast->next;
        }
        // 链表长度 n 小于 k
        if (!fast) {
            return fast;
        }
        ListNode* slow = pHead;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
