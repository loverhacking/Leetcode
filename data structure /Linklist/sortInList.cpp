// 单链表的排序 (来源： 牛客 BM12)
// 描述: 给定一个节点数为n的无序单链表，对其按升序排序。
// 0<n≤100000，保证节点权值在[−10^9, 10^9]之内。
// 要求：空间复杂度 O(n)，时间复杂度 O(nlogn)

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
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    // 归并排序 （自下而上）
    ListNode* sortInList(ListNode* head) {
        // write code here
        if (!head || !head->next) return head;
        vector<ListNode*> v;
        ListNode* t = head;
        while (t) {
            ListNode* temp = t->next;
            t->next = nullptr;
            v.push_back(t);
            t = temp;
        }
        while (v.size() > 1) {
            vector<ListNode*> temp;
            while (!v.empty()) {
                ListNode* first = v.back(); // 获取最后一个元素
                v.pop_back(); // 移除最后一个元素
                ListNode* second = v.empty()? nullptr : v.back();
                if (!v.empty()) v.pop_back();  // 确保第二个元素存在时才弹出
                temp.push_back(merge(first, second));
            }
            v = temp;
        }
        return v.at(0);
    }

    // 归并排序 （递归方式）
    /*
    ListNode* sortInList(ListNode* head) {
        // write code here
        if (!head || !head->next) return head;
        ListNode* fast = head->next; // 确保slow 位于左半部分(e.g. 1 2）
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* middle = slow->next;
        slow->next = nullptr; // 切断前后两部分
        return merge(sortInList(middle), sortInList(head));
    }
    */

    ListNode* merge(ListNode* p1, ListNode* p2) {
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

   /* 快速排序
   ListNode* sortInList(ListNode* head) {
        // write code here
        if (!head || !head->next) return head;
        return quickSort(head, nullptr);
    }
    */

   ListNode* quickSort(ListNode* head, ListNode* tail) {
        if (head == tail || head->next == tail) return head;

        ListNode* pivot = partion(head, tail);

        quickSort(head, pivot);
        quickSort(pivot->next, tail);

        return head;

   }

    ListNode* partion(ListNode* head, ListNode* tail) {
        int val = head->val; // 选择第一个为基准值
        ListNode* first = head;
        ListNode* second = head->next;
        while (second != tail) {
            if (second->val < val) {
                first = first->next;
                swap(first->val, second->val);
            }
            second = second->next;
        }
        swap(head->val, first->val);
        return first;
    }
};