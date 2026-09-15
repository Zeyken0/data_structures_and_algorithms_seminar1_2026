#include <catch.hpp>
#include "selection_sort.h"
#include <vector>

TEST_CASE("SelectionSort: пустой массив", "[selection_sort]") {
    std::vector<int> arr;
    selection_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("SelectionSort: один элемент", "[selection_sort]") {
    std::vector<int> arr = {7};
    selection_sort(arr);
    REQUIRE(arr == std::vector<int>{7});
}

TEST_CASE("SelectionSort: уже отсортированный", "[selection_sort]") {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    selection_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("SelectionSort: обратный порядок", "[selection_sort]") {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    selection_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("SelectionSort: произвольный порядок", "[selection_sort]") {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    selection_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 1, 2, 3, 3, 4, 5, 5, 6, 9});
}

TEST_CASE("SelectionSort: дубликаты", "[selection_sort]") {
    std::vector<int> arr = {4, 4, 4, 4};
    selection_sort(arr);
    REQUIRE(arr == std::vector<int>{4, 4, 4, 4});
}

TEST_CASE("SelectionSort: отрицательные и положительные", "[selection_sort]") {
    std::vector<int> arr = {5, -3, 0, -8, 2, -1};
    selection_sort(arr);
    REQUIRE(arr == std::vector<int>{-8, -3, -1, 0, 2, 5});
}

TEST_CASE("SelectionSort: double", "[selection_sort][double]") {
    SECTION("положительные дробные") {
        std::vector<double> arr = {3.5, 1.25, 2.75, 0.5, 4.0};
        selection_sort(arr);
        REQUIRE(arr == std::vector<double>{0.5, 1.25, 2.75, 3.5, 4.0});
    }
    SECTION("отрицательные и положительные") {
        std::vector<double> arr = {-1.5, 2.25, -3.75, 0.0, 1.5};
        selection_sort(arr);
        REQUIRE(arr == std::vector<double>{-3.75, -1.5, 0.0, 1.5, 2.25});
    }
    SECTION("пустой массив") {
        std::vector<double> arr;
        selection_sort(arr);
        REQUIRE(arr.empty());
    }
}
