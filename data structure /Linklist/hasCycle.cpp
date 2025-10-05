// 判断链表中是否有环(来源： 牛客 BM6)
// 描述判断给定的链表中是否有环。如果有环则返回true，否则返回false。
// 数据范围：链表长度 0 <= n <= 10000，链表中任意节点的值满足 ∣val∣<=100000
// 要求：空间复杂度 O(1)，时间复杂度 O(n)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

// 快慢指针法： 为何有环下快慢指针必能相遇
// 设： 环外部分长度为 L（从头节点到环入口的距离）环的长度为 C
// 慢指针每次走1步，快指针每次走2步
// 设慢指针进入环时，快指针在环中的位置为 k（0 ≤ k < C）

// 情况1：k = 0（慢指针进入环时两指针重合）
// 这种情况很简单，两指针已经相遇。

// 情况2：k > 0（慢指针进入环时两指针不重合）
// 设时间 t 后两指针相遇，则：

// 慢指针在环中走了 t 步 (慢指针位置) = t mod C
// 快指针在环中走了 2t 步 (快指针位置) = (k + 2t) mod C
// 两指针在环中的位置差应该满足相遇条件
// t mod C = (k + 2t) mod C
// 则有 t + mC = k + 2t (m 为任意整数）
// => t = mC - k 因此对于任意 k, t总是有解的， 故总能相遇

// 推广到其他速度比
// 对于快指针走 m 步，慢指针走 n 步的情况（m > n），相遇的条件是
// nt mod C = (k + mt) mod C
// 则有 nt + mC = k + mt (m 为任意整数）
// => t = (mc - k) / (m - n)
// 当且仅当 m - n 与 C 互质时，对于任意 k 都有解。这就是为什么通常选择 m=2, n=1，因为 1 与任何 C 都互质。

