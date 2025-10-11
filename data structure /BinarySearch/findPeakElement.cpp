// 寻找峰值 （来源牛客：BM19）
// 描述: 给定一个长度为n的数组nums，请你找到峰值并返回其索引。数组可能包含多个峰值，在这种情况下，返回任何一个所在位置即可。
// 峰值元素是指其值严格大于左右相邻值的元素。严格大于即不能有等于
// 假设 nums[-1] = nums[n] = −∞
// 对于所有有效的 i 都有 nums[i] != nums[i + 1]
// 时间复杂度 O(logN)
// 数据范围：1≤nums.length≤2×10^5, −2^31 <=nums[i]<=2^31−1

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int findPeakElement(vector<int>& nums) {
        // write code here
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] > nums[middle + 1]) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        return left; // 当left == right时，找到峰值
    }
};

//初始时，左指针在位置0，右指针在位置n-1
// 每次迭代，搜索区间减半
// 由于数组两端视为负无穷，且相邻元素不相等，数组中必然存在峰值
// 算法总能找到一个峰值，因为：
//    如果 nums[mid] < nums[mid+1]，说明右侧有更大的值，将左指针移动到 mid+1（右边大小情况 /\, 或者 //）
//    如果 nums[mid] > nums[mid+1]，则峰值可能在 mid 或左侧，将右指针移动到 mid (左边 /\, 或者\\)
// 这种方法的时间复杂度是 O(logN)，空间复杂度是 O(1)，满足题目要求。