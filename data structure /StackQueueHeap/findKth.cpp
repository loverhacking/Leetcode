// 寻找第K大 (来源： 牛客 BM47)
// 描述: 有一个整数数组，请你根据快速排序的思路，找出数组中第 k 大的数。
// 给定一个整数数组 a ,同时给定它的大小n和要找的 k ，请返回第 k 大的数(包括重复的元素，不用去重)，保证答案存在。
// 要求：时间复杂度 O(nlogn)，空间复杂度 O(1)

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param a int整型vector
     * @param n int整型
     * @param K int整型
     * @return int整型
     */
    int findKth(vector<int>& a, int n, int K) {
        // write code here
        if (n <= 1) return a[0];
        return quickSortHelper(a, 0, n - 1, K);
    }

private:
    int quickSortHelper(vector<int>& a, int left, int right, int K) {
        if (left == right) return a[left];
        int pivot = partion(a, left, right);
        if (pivot == a.size() - K) {
            return a[pivot];
        } else if (pivot < a.size() - K) {
            return quickSortHelper(a, pivot + 1, right, K);
        } else {
            return quickSortHelper(a, left, pivot - 1, K);
        }
    }

    int partion(vector<int>& a, int left, int right) {
        // cai
        int pivotIndex = left + rand() % (right - left + 1);
        int pivot = a[pivotIndex];

        // 将基准值交换到最左边
        swap(a[pivotIndex], a[left]);

        // 分区：大于基准值的放右边，小于等于的放左边
        int first = left;
        int second = left + 1;
        while (second <= right) {
            if (a[second] < pivot) {
                first++;
                swap(a[first], a[second]);
            }
            second++;
        }
        swap(a[first], a[left]);
        return first;
    }
};
