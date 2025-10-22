#include "pch.h"
#include "quick_sort.h"
#include <utility> // for std::swap

namespace clrs {
    namespace algo {
        void quick_sort_recursive(std::vector<int>& a, int zuo, int you) {
            if (zuo >= you) {
                return;
            }
            int z = zuo - 1;int y = you + 1;
            int mid_val = a[(zuo + you) / 2];
            while (z < y) {
                do z++; while (a[z] > mid_val);
                do y--; while (a[y] < mid_val);
                if (z < y) std::swap(a[z], a[y]);     
            }
            quick_sort_recursive(a, zuo, y);  quick_sort_recursive(a, y + 1, you);
        }
        void quick_sort(std::vector<int>& a) {
            if (a.empty()) {
                return;
            }
            quick_sort_recursive(a, 0, static_cast<int>(a.size() - 1));
        }
    } // namespace algo
} // namespace clrs