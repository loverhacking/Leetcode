// 最小的K个数 (来源： 牛客 BM46)
// 描述: 给定一个长度为 n 的可能有重复值的数组，找出其中不去重的最小的 k 个数。
// 要求：空间复杂度 O(n) ，时间复杂度 O(nlogk)

#include <queue>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param input int整型vector
     * @param k int整型
     * @return int整型vector
     */
    vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
        // write code here
        if (k == 0) return {};
        if (k >= input.size()) return input;

        for (auto& num : input) {
            if (pq.size() < k) {
                pq.push(num);
            } else if (num < pq.top()) {
                pq.push(num);
                pq.pop();
            }
        }

        vector<int> v;
        while (!pq.empty()) {
            v.push_back(pq.top());
            pq.pop();
        }
        return v;
    }

private:
    // 采用最大堆，记录当前堆中最大值
    priority_queue<int, vector<int>> pq; // 默认最大堆
};