// 二分查找-I （来源牛客：BM17）
// 描述: 请实现无重复数字的升序数组的二分查找
// 给定一个 元素升序的、无重复数字的整型数组 nums 和一个目标值 target ，写一个函数搜索 nums 中的 target，
// 如果目标值存在返回下标（下标从 0 开始），否则返回 -1
// 数据范围：0≤len(nums)≤2×10^ 5, 数组中任意值满足 ∣val∣≤10^ 9
// 时间复杂度 O(logn) ，空间复杂度 O(1)

#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @param target int整型
     * @return int整型
     */
    int search(vector<int>& nums, int target) {
        // write code here
        if (nums.empty()) return -1;
        return binarySearch(nums, target, 0, nums.size() - 1);
    }

    // 非递归写法
    int binarySearch(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] == target) return middle;
            if (nums[middle] > target) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return -1;
    }

    // 递归写法
    /*
    int binarySearch(vector<int>& nums, int target, int left, int right) {
        if (left > right) return -1;
        int middle = left + (right - left) / 2;
        if (nums[middle] == target) return middle;
        if (nums[middle] < target)
            return binarySearch(nums, target, middle + 1, right);
        else
            return binarySearch(nums, target, left, middle - 1);
    }
    */
};