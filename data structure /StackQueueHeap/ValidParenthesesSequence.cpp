// 有效括号序列 (来源： 牛客 BM44)
// 描述: 给出一个仅包含字符仅由括号字符 '[', ']', '(', ')', '{', '}'的括号序列字符串 s
// 你需要判断给出的括号序列字符串 s 是否是有效的括号序列。
// 有效括号序列的定义如下：
//    空序列是有效括号序列；
//    如果 A 是有效括号序列，则 (A)、 [A]、 A 都是有效括号序列；
//    如果 A 和 B 都是有效括号序列，则它们的拼接 AB 也是有效括号序列。
// 如果括号序列字符串 s 是有效的括号序列，返回一个布尔值 true；否则返回一个布尔值 false


class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         *
         * @param s string字符串
         * @return bool布尔型
         */
        bool isValid(string s) {
            // write code here
            if (s.size() <= 1) return false;
            for (int i = 0; i < s.size(); i++) {
                if (stk.empty()) {
                    stk.push(s[i]);
                } else {
                    char c = stk.top();
                    if ((c == '[' && s[i] == ']') || (c == '(' && s[i] == ')') || (c == '{' && s[i] == '}')) {
                        stk.pop();
                    } else {
                        stk.push(s[i]);
                    }
                }
            }
            return stk.empty();
        }
    private:
        stack<char> stk;
};
