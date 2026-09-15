#include "bubble_sort.h"

template <typename T>
void bubble_sort(std::vector<T>& arr) {
    const std::size_t n = arr.size();
    if (n < 2) return;

    for (std::size_t i = 0; i + 1 < n; ++i) {
        for (std::size_t j = 0; j + 1 < n - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template void bubble_sort<int>(std::vector<int>&);
template void bubble_sort<double>(std::vector<double>&);
template void bubble_sort<float>(std::vector<float>&);
