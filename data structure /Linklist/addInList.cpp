// 链表相加(二) （来源：牛客 BM11）
// 描述: 假设链表中每一个节点的值都在 0 - 9 之间，那么链表整体就可以代表一个整数。
// 给定两个这种链表，请生成代表两个整数相加值的结果链表。
// 数据范围：0≤n,m≤1000000，链表任意值 0≤val≤9
// 要求：空间复杂度 O(1)，时间复杂度 O(n)

/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        if (!head1) return head2;
        if (!head2) return head1;
        head1 = reverse(head1);
        head2 = reverse(head2);
        ListNode* p1 = head1;
        ListNode* p2 = head2;
        ListNode* sentinel = new ListNode(-1);
        sentinel->next = head2;
        ListNode* prev = sentinel;
        int jinwei = 0;
        int sum = 0;

        while (p1 && p2) {
            sum = p1->val + p2->val + jinwei;
            p2->val = sum % 10;
            jinwei = sum / 10;
            prev = prev->next;
            p1 = p1->next;
            p2 = p2->next;
        }

        if (p1) { // p1剩余部分
            prev->next = p1;
            while (true) {
                sum = p1->val + jinwei;
                p1->val = sum % 10;
                jinwei = sum / 10;
                if (sum < 10) break;
                if (!p1->next)
                    p1->next = new ListNode(0);
                p1 = p1->next;
            }
        } else if (p2){ // p2剩余部分
            while (true) {
                sum = p2->val + jinwei;
                p2->val = sum % 10;
                jinwei = sum / 10;
                if (sum < 10) break;
                if (!p2->next)
                    p2->next = new ListNode(0);
                p2 = p2->next;
            }
        } else if (jinwei > 0) { // p1 和 p2 同时结束，但还有进位
            prev->next = new ListNode(jinwei);
        }
        return reverse(head2);
    }

    // 辅助方法：翻转链表
    ListNode* reverse(ListNode * head) {
        if (!head || !head->next) return head;
        ListNode* prev = nullptr;
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
