#include <catch.hpp>
#include "optimized_bubble_sort.h"
#include <vector>

TEST_CASE("OptimizedBubbleSort: пустой массив", "[optimized_bubble_sort]") {
    std::vector<int> arr;
    optimized_bubble_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("OptimizedBubbleSort: один элемент", "[optimized_bubble_sort]") {
    std::vector<int> arr = {13};
    optimized_bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{13});
}

TEST_CASE("OptimizedBubbleSort: уже отсортированный", "[optimized_bubble_sort]") {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    optimized_bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8});
}

TEST_CASE("OptimizedBubbleSort: обратный порядок", "[optimized_bubble_sort]") {
    std::vector<int> arr = {8, 7, 6, 5, 4, 3, 2, 1};
    optimized_bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8});
}

TEST_CASE("OptimizedBubbleSort: произвольный порядок", "[optimized_bubble_sort]") {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    optimized_bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 1, 2, 3, 3, 4, 5, 5, 6, 9});
}

TEST_CASE("OptimizedBubbleSort: почти отсортированный", "[optimized_bubble_sort]") {
    std::vector<int> arr = {1, 2, 3, 5, 4, 6, 7, 8};
    optimized_bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8});
}

TEST_CASE("OptimizedBubbleSort: отрицательные", "[optimized_bubble_sort]") {
    std::vector<int> arr = {-1, 0, -5, 3, -2};
    optimized_bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{-5, -2, -1, 0, 3});
}

TEST_CASE("OptimizedBubbleSort: double", "[optimized_bubble_sort][double]") {
    SECTION("положительные дробные") {
        std::vector<double> arr = {3.5, 1.25, 2.75, 0.5, 4.0};
        optimized_bubble_sort(arr);
        REQUIRE(arr == std::vector<double>{0.5, 1.25, 2.75, 3.5, 4.0});
    }
    SECTION("отрицательные и положительные") {
        std::vector<double> arr = {-1.5, 2.25, -3.75, 0.0, 1.5};
        optimized_bubble_sort(arr);
        REQUIRE(arr == std::vector<double>{-3.75, -1.5, 0.0, 1.5, 2.25});
    }
    SECTION("пустой массив") {
        std::vector<double> arr;
        optimized_bubble_sort(arr);
        REQUIRE(arr.empty());
    }
}
