#include "exchange_sort.h"

template <typename T>
void exchange_sort(std::vector<T>& arr) {
    const std::size_t n = arr.size();
    if (n < 2) return;

    for (std::size_t i = 0; i + 1 < n; ++i) {
        for (std::size_t j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

template void exchange_sort<int>(std::vector<int>&);
template void exchange_sort<double>(std::vector<double>&);
template void exchange_sort<float>(std::vector<float>&);
