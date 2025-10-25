//  数组中的逆序对 (来源：牛客 BM20)
// 描述： 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
// 输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P mod 1000000007
// 要求：空间复杂度 O(n)，时间复杂度 O(nlogn)

#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int InversePairs(vector<int>& nums) {
        // write code here
        if (nums.size() < 2) return 0;
        vector<int> tmp(nums.size());    // 辅助数组 预先分配空间
        return mergeSort(nums, tmp, 0, nums.size() - 1) % 1000000007;
    }

private:
    // 借助归并排序实现
    int mergeSort(vector<int>& nums, vector<int>& tmp, int left, int right) {
        if (left >= right) return 0;
        int cnt = 0;
        int middle = left + (right - left) / 2;
        cnt += mergeSort(nums, tmp, left, middle);
        cnt += mergeSort(nums, tmp, middle + 1, right);
        cnt += merge(nums, tmp, left, middle, right);
        return cnt % 1000000007;
    }

    int merge(vector<int>& nums, vector<int>& tmp, int left, int middle ,int right) {
        int i = left;
        int j = middle + 1;
        int k = left;
        int cnt = 0;
        // 合并：左子数组 [left, middle] 右子数组 [middle + 1, right]
        while (i <= middle && j <= right) {
            if (nums[i] <= nums[j]) {
                tmp[k] = nums[i];
                k++;
                i++;
            } else {
                tmp[k] = nums[j];
                // 当左子数组的当前元素大于右子数组的当前元素时，
                // 计算左子数组当前元素及其后所有元素与右子数组当前元素构成的逆序对数量
                cnt += (middle - i + 1);
                k++;
                j++;
            }
        }

        // 合并左子数组剩余元素
        while (i <= middle) {
            tmp[k] = nums[i];
            k++;
            i++;
        }

        // 合并右子数组剩余元素
        while (j <= right) {
            tmp[k] = nums[j];
            k++;
            j++;
        }

        // 更新原数组
        for (i = left; i <= right; i++) {
            nums[i] = tmp[i];
        }
        return cnt % 1000000007;
    }
};