#include "insertion_sort.h"

template <typename T>
void insertion_sort(std::vector<T>& arr) {
    const std::size_t n = arr.size();
    if (n < 2) return;

    for (std::size_t i = 1; i < n; ++i) {
        T key = arr[i];
        std::size_t j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
}

template void insertion_sort<int>(std::vector<int>&);
template void insertion_sort<double>(std::vector<double>&);
template void insertion_sort<float>(std::vector<float>&);
