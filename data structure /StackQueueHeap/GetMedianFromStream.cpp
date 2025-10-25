// 数据流中的中位数 (来源： 牛客 BM48)
// 描述: 如何得到一个数据流中的中位数？
//     如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
//     如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
// 我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
// 空间复杂度 O(n)  ， 时间复杂度 O(nlogn)

#include <queue>
class Solution {
public:
    void Insert(int num) {
        maxHeap.push(num);

        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double GetMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.top();
        }
    }

private:
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};

// 中位数是指：有序数组中中间的那个数。则根据中位数可以把数组分为如下三段:
// [0 ... median - 1], [median], [median + 1 ... arr.size() - 1]，即[中位数的左边，中位数，中位数的右边]
// 那么，如果我有个数据结构保留[0...median-1]的数据，并且可以O(1)时间取出最大值，即arr[0...median-1]中的最大值
// 相对应的，如果我有个数据结构可以保留[median + 1 ... arr.size() - 1] 的数据， 并且可以O(1)时间取出最小值，即
// arr[median + 1 ... arr.size() - 1] 中的最小值。
// 然后，我们把[median]即中位数，随便放到哪个都可以。

// 假设[0 ... median - 1]的长度为l_len, [median + 1 ... arr.sise() - 1]的长度为 r_len.
//    1.如果l_len == r_len + 1, 说明，中位数是左边数据结构的最大值
//    2.如果l_len + 1 == r_len, 说明，中位数是右边数据结构的最小值
//    3.如果l_len == r_len, 说明，中位数是左边数据结构的最大值与右边数据结构的最小值的平均值。

// 说了这么多，一个数据结构可以O(1)返回最小值的，其实就是小根堆，
// O(1)返回最大值的，其实就是大根堆。并且每次插入到堆中的时间复杂度为O(logn)

// 所以，GetMedian()操作算法过程为：
//     初始化一个大根堆，存中位数左边的数据，一个小根堆，存中位数右边的数据
//     动态维护两个数据结构的大小，即最多只相差一个