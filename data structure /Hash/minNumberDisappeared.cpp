// 缺失的第一个正整数 (来源：牛客 BM53）
// 描述: 给定一个无重复元素的整数数组nums，请你找出其中没有出现的最小的正整数
//  空间复杂度 O(1)，时间复杂度 O(n)

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int minNumberDisappeared(vector<int>& nums) {
        // write code here
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0) {
                nums[i] = nums.size() + 1;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (abs(nums[i]) <= nums.size()) {
                nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
            }
        }

        int ans = nums.size() + 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans =  i + 1;
                break;
            }
        }
        return ans;

    }
};

// 原地哈希
// 前面提到了数组要么缺失 1～n中的某个数字，要么缺失 n+1，而数组正好有下标 0～n−1可以对应数字 1～n，因此只要数字
// 1～n中某个数字出现，我们就可以将对应下标的值做一个标记，最后没有被标记的下标就是缺失的值。

// 具体做法：
//     step 1：先遍历数组将所有的负数都修改成n+1。
//     step 2：然后再遍历数组，每当遇到一个元素绝对值不超过n时，则表示这个元素是1～n中出现的元素，我们可以将这个数值对应的下标里的元素改成负数，
//                相当于每个出现过的正整数，我们把与它值相等的下标都指向一个负数（表示已经出现过），这就是类似哈希表的实现原理的操作。
//     step 3：最后遍历数组的时候碰到的第一个非负数，它的下标就是没有出现的第一个正整数，因为它在之前的过程中没有被修改，说明它这个下标对应的正整数没有出现过。