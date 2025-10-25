// 三数之和  (来源：牛客 BM54）
// 描述: 给出一个有n个元素的数组S，S中是否有元素a,b,c满足a+b+c=0？找出数组S中所有满足条件的三元组。
// 空间复杂度：O(n^2)，时间复杂度 O(n^2)
// 注意： 三元组（a、b、c）中的元素必须按非降序排列。（即a≤b≤c）
// 解集中不能包含重复的三元组。

#include <unordered_map>
#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param num int整型vector
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > threeSum(vector<int>& num) {
        // write code here
        if (num.size() < 3) return {};
        // 解法：排序后使用双指针
        sort(num.begin(), num.end());

        vector<vector<int>> v;

        for (int i = 0; i < num.size() - 2; i++) {
            // 跳过重复元素
            if (i > 0 && num[i] == num[i - 1]) continue;

            int left = i + 1;
            int right = num.size() - 1;
            // 使用双指针
            while (left < right) {
                int sum = num[left] + num[right];
                if (sum + num[i] == 0) {
                    v.push_back({num[i], num[left], num[right]});
                    //  跳过重复元素
                    while (left < right && num[left + 1] == num[left]) left++;
                    while (left < right && num[right - 1] == num[right]) right--;
                    left++;
                    right--;
                }
                else if (sum + num[i] < 0) left++;
                else right--;
            }
        }
        return v;

    }
};