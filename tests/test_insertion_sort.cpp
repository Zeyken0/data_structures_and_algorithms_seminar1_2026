#include <catch.hpp>
#include "insertion_sort.h"
#include <vector>

TEST_CASE("InsertionSort: пустой массив", "[insertion_sort]") {
    std::vector<int> arr;
    insertion_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("InsertionSort: один элемент", "[insertion_sort]") {
    std::vector<int> arr = {0};
    insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{0});
}

TEST_CASE("InsertionSort: уже отсортированный", "[insertion_sort]") {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("InsertionSort: обратный порядок", "[insertion_sort]") {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("InsertionSort: произвольный порядок", "[insertion_sort]") {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 1, 2, 3, 3, 4, 5, 5, 6, 9});
}

TEST_CASE("InsertionSort: много дубликатов", "[insertion_sort]") {
    std::vector<int> arr = {5, 1, 5, 1, 5, 1};
    insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 1, 1, 5, 5, 5});
}

TEST_CASE("InsertionSort: отрицательные числа", "[insertion_sort]") {
    std::vector<int> arr = {-1, -5, -3, -2, -4};
    insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{-5, -4, -3, -2, -1});
}

TEST_CASE("InsertionSort: double", "[insertion_sort][double]") {
    SECTION("положительные дробные") {
        std::vector<double> arr = {3.5, 1.25, 2.75, 0.5, 4.0};
        insertion_sort(arr);
        REQUIRE(arr == std::vector<double>{0.5, 1.25, 2.75, 3.5, 4.0});
    }
    SECTION("отрицательные и положительные") {
        std::vector<double> arr = {-1.5, 2.25, -3.75, 0.0, 1.5};
        insertion_sort(arr);
        REQUIRE(arr == std::vector<double>{-3.75, -1.5, 0.0, 1.5, 2.25});
    }
    SECTION("пустой массив") {
        std::vector<double> arr;
        insertion_sort(arr);
        REQUIRE(arr.empty());
    }
}
