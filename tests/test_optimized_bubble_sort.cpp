#include <catch.hpp>
#include "optimized_bubble_sort.h"
#include <vector>

TEST_CASE("OptimizedBubbleSort: пустой массив", "[optimized_bubble_sort]") {
    std::vector<int> arr;
    optimized_bubble_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("OptimizedBubbleSort: один элемент", "[optimized_bubble_sort]") {
    std::vector<int> arr = {12};
    optimized_bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{12});
}

TEST_CASE("OptimizedBubbleSort: уже отсортированный", "[optimized_bubble_sort]") {
    std::vector<int> arr = {0, 2, 5, 6, 8, 12, 14, 18};
    optimized_bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("OptimizedBubbleSort: обратный порядок", "[optimized_bubble_sort]") {
    std::vector<int> arr = {18, 14, 12, 8, 6, 5, 2, 0};
    optimized_bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("OptimizedBubbleSort: тестовый массив", "[optimized_bubble_sort]") {
    std::vector<int> arr = {12, 6, 0, 14, 5, 18, 2, 8};
    optimized_bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("OptimizedBubbleSort: почти отсортированный", "[optimized_bubble_sort]") {
    std::vector<int> arr = {0, 2, 5, 6, 12, 8, 14, 18};
    optimized_bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("OptimizedBubbleSort: отрицательные", "[optimized_bubble_sort]") {
    std::vector<int> arr = {-12, -6, 0, -14, -5, -18, -2, -8};
    optimized_bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{-18, -14, -12, -8, -6, -5, -2, 0});
}

TEST_CASE("OptimizedBubbleSort: два элемента, оба порядка", "[optimized_bubble_sort]") {
    SECTION("по возрастанию") {
        std::vector<int> arr = {6, 12};
        optimized_bubble_sort(arr);
        REQUIRE(arr == std::vector<int>{6, 12});
    }
    SECTION("по убыванию") {
        std::vector<int> arr = {12, 6};
        optimized_bubble_sort(arr);
        REQUIRE(arr == std::vector<int>{6, 12});
    }
}

TEST_CASE("OptimizedBubbleSort: double", "[optimized_bubble_sort][double]") {
    SECTION("положительные дробные") {
        std::vector<double> arr = {6.0, 3.0, 0.0, 7.0, 2.5, 9.0, 1.0, 4.0};
        optimized_bubble_sort(arr);
        REQUIRE(arr == std::vector<double>{0.0, 1.0, 2.5, 3.0, 4.0, 6.0, 7.0, 9.0});
    }
    SECTION("отрицательные и положительные") {
        std::vector<double> arr = {-6.0, 3.0, 0.0, -7.0, 2.5, -9.0, 1.0, 4.0};
        optimized_bubble_sort(arr);
        REQUIRE(arr == std::vector<double>{-9.0, -7.0, -6.0, 0.0, 1.0, 2.5, 3.0, 4.0});
    }
    SECTION("пустой массив") {
        std::vector<double> arr;
        optimized_bubble_sort(arr);
        REQUIRE(arr.empty());
    }
}
