// 二维数组中的查找 （来源牛客：BM18）
// 描述: 在一个二维数组array中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
// 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
// 数据范围：矩阵的长宽满足 0≤n,m≤500 ， 矩阵中的值满足 −10^9≤val≤10^9
// 进阶：空间复杂度 O(1) ，时间复杂度 O(n+m)

#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param target int整型
     * @param array int整型vector<vector<>>
     * @return bool布尔型
     */
    bool Find(int target, vector<vector<int> >& array) {
        // write code here
        if (array.empty()) return false;
        if (array.size() == 1 && array[0].empty()) return false; // check case: [[]]
        int i = array.size() - 1, j = 0; // 开始位于左下角
        while (inArray(i, j, array)) {
            if (array[i][j] == target) return true;
            if (target > array[i][j]) j++;
            else i--;
        }
        return false;
    }

    bool inArray(int& i, int& j, vector<vector<int>>& array) {
        return i >= 0 && i <= array.size() - 1 && j >= 0 && j <= array[0].size() - 1;
    }
};

// 从左下角开始查找：
// 如果当前元素等于目标值，直接返回true。
// 如果当前元素大于目标值，由于行是递增的，当前行右边的所有元素都会比目标值大，因此可以排除当前行，向上移动一行。
// 如果当前元素小于目标值，由于列是递增的，当前列上边的所有元素都会更小，因此可以排除当前列，向右移动一列。
// 算法选择：这种搜索路径确保了每次操作都能排除一行或一列，从而在O(n + m)的时间内完成搜索，其中n和m分别是矩阵的行数和列数。