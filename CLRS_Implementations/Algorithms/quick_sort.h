#pragma once
#include <vector>

namespace clrs {
    namespace algo {

        /**
         * @brief 快速排序 (降序) - 内部递归函数
         * @param a   要排序的 vector (引用传递)
         * @param zuo 左边界
         * @param you 右边界
         */
        void quick_sort_recursive(std::vector<int>& a, int zuo, int you);


        /**
         * @brief 快速排序 (降序) - 用户调用的“入口”函数
         * @param a 要排序的 vector (引用传递)
         * @note 自动使用 0 和 size()-1 作为边界
         */
        void quick_sort(std::vector<int>& a);

    } // namespace algo
} // namespace clrs