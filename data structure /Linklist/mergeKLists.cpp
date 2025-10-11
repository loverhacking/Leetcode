// 合并k个已排序的链表 (来源： 牛客 BM5）
// 描述: 合并 k 个升序的链表并将结果作为一个升序的链表返回其头节点。
// 数据范围：节点总数 0≤n≤5000，每个节点的val满足 ∣val∣<=1000
// 要求：时间复杂度 O(nlogn)

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <queue>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param lists ListNode类vector
     * @return ListNode类
     */
    // 采用优先级队列
    // 时间复杂度 o(nlogn)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // write code here
        if (lists.empty()) return nullptr;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto it : lists) {
            for (ListNode* t = it; t != nullptr; t = t->next) {
                pq.push(t->val);
            }
        }
        ListNode* sentinel = new ListNode(-1);
        ListNode* t = sentinel;
        while(!pq.empty()) {
            t->next = new ListNode(pq.top());
            pq.pop();
            t = t->next;
        }
        return sentinel->next;
    }

    // 采用分治思想，两两合并
    // 时间复杂度 o(nlogk)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // write code here
        if (lists.empty()) return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode* merge(vector<ListNode*>& lists, int left, int right) {
        if (left == right) return lists[left];
        if (left > right) return nullptr;
        int middle = left + (right - left) / 2;

        ListNode* first = merge(lists, left, middle);
        ListNode* second = merge(lists, middle + 1, right);

        return mergeTwoLists(first, second);
    }

    ListNode* mergeTwoLists(ListNode* p1, ListNode* p2) {
        if (!p1) return p2;
        if (!p2) return p1;
        ListNode* sentinel = new ListNode(-1);
        ListNode* cur = sentinel;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                cur->next = p1;
                p1 = p1->next;
            } else {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        cur->next = p1? p1 : p2;
        return sentinel->next;
    }
};