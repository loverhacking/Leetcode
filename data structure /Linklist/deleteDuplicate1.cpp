// 删除有序链表中重复的元素-I (来源：牛客 BM15）
// 描述：删除给出链表中的重复元素（链表中元素从小到大有序），使链表中的所有元素都只出现一次
// 数据范围：链表长度满足 0≤n≤100，链表中任意节点的值满足 ∣val∣≤100

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
    ListNode* deleteDuplicates1(ListNode* head) {
        // write code here
        if (!head ||!head->next) return head;
        ListNode* cur = head;

        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;

    }
};