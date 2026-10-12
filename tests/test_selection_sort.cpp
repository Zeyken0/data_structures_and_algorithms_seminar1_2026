#include <catch.hpp>
#include "selection_sort.h"
#include <vector>

TEST_CASE("SelectionSort: пустой массив", "[selection_sort]") {
    std::vector<int> arr;
    selection_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("SelectionSort: один элемент", "[selection_sort]") {
    std::vector<int> arr = {12};
    selection_sort(arr);
    REQUIRE(arr == std::vector<int>{12});
}

TEST_CASE("SelectionSort: уже отсортированный", "[selection_sort]") {
    std::vector<int> arr = {0, 2, 5, 6, 8, 12, 14, 18};
    selection_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("SelectionSort: обратный порядок", "[selection_sort]") {
    std::vector<int> arr = {18, 14, 12, 8, 6, 5, 2, 0};
    selection_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("SelectionSort: тестовый массив", "[selection_sort]") {
    std::vector<int> arr = {12, 6, 0, 14, 5, 18, 2, 8};
    selection_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("SelectionSort: дубликаты", "[selection_sort]") {
    std::vector<int> arr = {12, 6, 0, 14, 5, 18, 2, 8, 12, 6, 0, 14, 5, 18, 2, 8};
    selection_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 0, 2, 2, 5, 5, 6, 6, 8, 8, 12, 12, 14, 14, 18, 18});
}

TEST_CASE("SelectionSort: отрицательные и положительные", "[selection_sort]") {
    std::vector<int> arr = {-12, -6, 0, -14, -5, -18, -2, -8};
    selection_sort(arr);
    REQUIRE(arr == std::vector<int>{-18, -14, -12, -8, -6, -5, -2, 0});
}

TEST_CASE("SelectionSort: два элемента, оба порядка", "[selection_sort]") {
    SECTION("по возрастанию") {
        std::vector<int> arr = {6, 12};
        selection_sort(arr);
        REQUIRE(arr == std::vector<int>{6, 12});
    }
    SECTION("по убыванию") {
        std::vector<int> arr = {12, 6};
        selection_sort(arr);
        REQUIRE(arr == std::vector<int>{6, 12});
    }
}

TEST_CASE("SelectionSort: double", "[selection_sort][double]") {
    SECTION("положительные дробные") {
        std::vector<double> arr = {6.0, 3.0, 0.0, 7.0, 2.5, 9.0, 1.0, 4.0};
        selection_sort(arr);
        REQUIRE(arr == std::vector<double>{0.0, 1.0, 2.5, 3.0, 4.0, 6.0, 7.0, 9.0});
    }
    SECTION("отрицательные и положительные") {
        std::vector<double> arr = {-6.0, 3.0, 0.0, -7.0, 2.5, -9.0, 1.0, 4.0};
        selection_sort(arr);
        REQUIRE(arr == std::vector<double>{-9.0, -7.0, -6.0, 0.0, 1.0, 2.5, 3.0, 4.0});
    }
    SECTION("пустой массив") {
        std::vector<double> arr;
        selection_sort(arr);
        REQUIRE(arr.empty());
    }
}
