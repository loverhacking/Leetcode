// 数组中只出现一次的两个数字 (来源：牛客 BM52）
// 描述: 一个整型数组里除了两个数字只出现一次，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
// 要求：空间复杂度 O(1)，时间复杂度 O(n)
// 提示：输出时按非降序排列。

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& nums) {
        // write code here
        int x_or = 0;
        for (auto num : nums) {
            x_or ^= num;
        }
        int low_bit = x_or & (-x_or);
        int a = 0, b = 0;
        for (auto num : nums) {
            if (low_bit & num) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        if (a > b) return {b, a};
        else return {a, b};
    }
};

// 关键步骤：
//     整体异或：首先计算数组中所有数字的异或结果，该结果等于两个只出现一次的数字的异或值。
//     分离数字：找到异或结果中最低位的1，该位表示两个数字在该位上不同。根据这一位将数组分成两组，每组分别异或得到两个目标数字。
//     结果处理：将得到的两个数字按升序排列后返回。
// 利用异或运算的性质:
//     异或运算具有交换性
//     相同数字异或结果为0，不同数字异或结果不为0。

// 为什么通过xor_result & -xor_result找到xor_result中最低位的1
// x =     aaaaaa1000...0
//~x =     bbbbbb0111...1
//~x + 1 = bbbbbb1000...0

//x       = aaaaaa1000...0
//~x + 1  = bbbbbb1000...0
//-----------------------
//结果     = 0000001000...0