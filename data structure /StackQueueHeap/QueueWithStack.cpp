// 用两个栈实现队列 (来源： 牛客 BM42)
// 描述: 用两个栈来实现一个队列，使用n个元素来完成 n 次在队列尾部插入整数(push)和n次在队列头部删除整数(pop)的功能。
// 队列中的元素为int类型。
// 保证操作合法，即保证pop操作时队列内已有元素。
// 要求：存储n个元素的空间复杂度为 O(n) ，插入与删除的时间复杂度都是 O(1)
class Solution
{
public:
    void push(int node) {
        stack1.push(node);

    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int elem = stack2.top();
        stack2.pop();
        return elem;

    }

private:
    stack<int> stack1;
    stack<int> stack2;
};


// push: 将数据直接压入stack1即可
// pop: 将stack1中的数据弹出压入到stack2中，则数据顺序相反，实现FIFO
// 为保证最先进入的数据一直处于栈顶，只有将stack2为空时，才能继续将stack1中的数据压入到stack2中