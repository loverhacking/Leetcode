// 链表中环的入口结点(来源： 牛客 BM7)
// 描述: 给一个长度为n链表，若其中包含环，请找出该链表的环的入口结点，否则，返回null。
// 数据范围：0 <= n <= 10000, 1<=结点值<=10000
// 要求：空间复杂度 O(1)，时间复杂度 O(n)

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (!pHead || !pHead->next) return nullptr;
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                ListNode* p = pHead;
                while (p != slow) {
                    p = p->next;
                    slow = slow->next;
                }
                return p;
            }
        }
        return nullptr;
    }
};

// 设 链表头节点到环入口距离为 a, 快慢指针相遇节点相对于环入口距离为 b, 环的长度为 c
// 则 快指针走的距离: a + c + b
// 慢指针走的距离：a + b
// 二者所画的时间相等，则有
// a + b = (a + c + b) / 2
// => a = c - b
// 可知 从相遇位置按链表方向移动到入口的距离 (c - b) 恰好等于链表头节点到环入口距离 (a)