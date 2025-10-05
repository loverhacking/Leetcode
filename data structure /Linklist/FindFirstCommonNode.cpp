// 两个链表的第一个公共结点(来源：牛客 BM10)
// 描述: 输入两个无环的单向链表，找出它们的第一个公共结点，如果没有公共节点则返回空。
// 要求：空间复杂度 O(1)，时间复杂度 O(n)

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1 || !pHead2) return nullptr;
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        while (p1 != p2) {
            p1 = (!p1)? pHead2 : p1->next;
            p2 = (!p2)? pHead1 : p2->next;
        }
        return p1;
    }
};

// 假设链表1距离公共节点距离 l1, 链表2距离公共节点距离 l2, 公共节点距离尾节点 s
// 则 通过两个指针分别遍历两个链表，当某个指针到达链表末尾时，将其指向另一个链表的头节点，这样两个指针会在公共节点相遇，
// 此时两者移动距离都为 (l1 + l2 + s)
// 或者同时到达末尾（nullptr）表示没有公共节点。