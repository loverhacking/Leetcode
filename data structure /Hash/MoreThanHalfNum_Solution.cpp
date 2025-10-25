// 数组中出现次数超过一半的数字 (来源：牛客 BM51）
// 描述: 给一个长度为 n 的数组，数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
// 要求：空间复杂度：O(1)，时间复杂度 O(n)

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return int整型
     */
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        // write code here
        int max_cnt_num = 0;
        int cnt = 0;
        for (auto num : numbers) {
            if (cnt == 0) {
                max_cnt_num = num;
                cnt = 1;
                continue;
            }
            if (max_cnt_num == num) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return max_cnt_num;
    }
};

// 数组中出现次数超过一半的数字即是数组中的众数
// 所以该问题可以归约为如何寻找众数（“打擂台”方法）