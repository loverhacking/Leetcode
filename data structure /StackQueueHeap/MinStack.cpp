// 包含min函数的栈 (来源： 牛客 BM43)
// 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的 min 函数，
// 输入操作时保证 pop、top 和 min 函数操作时，栈中一定有元素。
// 此栈包含的方法有：
//     push(value):将value压入栈中
//     pop():弹出栈顶元素
//     top():获取栈顶元素
//     min():获取栈中最小元素
// 栈的各个操作的时间复杂度是 O(1)，空间复杂度是 O(n)

class Solution {
    public:
        void push(int value) {
            stk.push(value);
            if (stkHelper.empty()) {
                stkHelper.push(value);
            } else {
                if (value <= min())
                    stkHelper.push(value);
            }
        }

        void pop() {
            if (stk.top() == min()) stkHelper.pop();
            stk.pop();
        }

        int top() {
            return stk.top();
        }

        int min() {
            return stkHelper.top();
        }
    private:
        stack<int> stk;
        stack<int> stkHelper;
};
