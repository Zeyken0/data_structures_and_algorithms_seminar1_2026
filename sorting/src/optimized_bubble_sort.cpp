#include "optimized_bubble_sort.h"

template <typename T>
void optimized_bubble_sort(std::vector<T>& arr) {
    const std::size_t n = arr.size();
    if (n < 2) return;

    for (std::size_t i = 0; i + 1 < n; ++i) {
        bool swapped = false;
        for (std::size_t j = 0; j + 1 < n - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

template void optimized_bubble_sort<int>(std::vector<int>&);
template void optimized_bubble_sort<double>(std::vector<double>&);
template void optimized_bubble_sort<float>(std::vector<float>&);
