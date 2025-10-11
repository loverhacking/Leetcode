// 链表的奇偶重排 (来源： 牛客 BM14)
// 描述： 给定一个单链表，请设定一个函数，将链表的奇数位节点和偶数位节点分别放在一起，重排后输出。
// 注意是节点的编号而非节点的数值。
// 数据范围：节点数量满足 0≤n≤10 节点中的值都满足 0≤val≤1000
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
    ListNode* oddEvenList(ListNode* head) {
        // write code here
        if (!head || !head->next) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* second = head->next; // 偶数链表头节点
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = second; // 连接奇偶数节点
        return head;

    }
};