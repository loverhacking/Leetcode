// 两数之和 (来源：牛客 BM50）
// 描述：给出一个整型数组 numbers 和一个目标值 target，请在数组中找出两个加起来等于目标值的数的下标，返回的下标按升序排列。
// 注：返回的数组下标从1开始算起，保证target一定可以由数组里面2个数字相加得到
// 要求：空间复杂度 O(n)，时间复杂度 O(nlogn)



#include <unordered_map>
#include <unordered_set>
#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @param target int整型
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        unordered_map<int, int> hashMap;
        for (int i = 0; i < numbers.size(); i++) {
            auto it = hashMap.find(target - numbers[i]);
            if (it == hashMap.end()) {
                hashMap[numbers[i]] = i;
            } else {
                return {it->second + 1, i + 1};
            }
        }
        return {};
    }
};