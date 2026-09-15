#include "selection_sort.h"

template <typename T>
void selection_sort(std::vector<T>& arr) {
    const std::size_t n = arr.size();
    if (n < 2) return;

    for (std::size_t i = 0; i + 1 < n; ++i) {
        std::size_t min_idx = i;
        for (std::size_t j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
        }
    }
}

template void selection_sort<int>(std::vector<int>&);
template void selection_sort<double>(std::vector<double>&);
template void selection_sort<float>(std::vector<float>&);
