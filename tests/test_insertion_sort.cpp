#include <catch.hpp>
#include "insertion_sort.h"
#include <vector>

TEST_CASE("InsertionSort: пустой массив", "[insertion_sort]") {
    std::vector<int> arr;
    insertion_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("InsertionSort: один элемент", "[insertion_sort]") {
    std::vector<int> arr = {12};
    insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{12});
}

TEST_CASE("InsertionSort: уже отсортированный", "[insertion_sort]") {
    std::vector<int> arr = {0, 2, 5, 6, 8, 12, 14, 18};
    insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("InsertionSort: обратный порядок", "[insertion_sort]") {
    std::vector<int> arr = {18, 14, 12, 8, 6, 5, 2, 0};
    insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("InsertionSort: тестовый массив", "[insertion_sort]") {
    std::vector<int> arr = {12, 6, 0, 14, 5, 18, 2, 8};
    insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("InsertionSort: много дубликатов", "[insertion_sort]") {
    std::vector<int> arr = {12, 6, 0, 14, 5, 18, 2, 8, 12, 6, 0, 14, 5, 18, 2, 8};
    insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 0, 2, 2, 5, 5, 6, 6, 8, 8, 12, 12, 14, 14, 18, 18});
}

TEST_CASE("InsertionSort: отрицательные числа", "[insertion_sort]") {
    std::vector<int> arr = {-12, -6, 0, -14, -5, -18, -2, -8};
    insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{-18, -14, -12, -8, -6, -5, -2, 0});
}

TEST_CASE("InsertionSort: два элемента, оба порядка", "[insertion_sort]") {
    SECTION("по возрастанию") {
        std::vector<int> arr = {6, 12};
        insertion_sort(arr);
        REQUIRE(arr == std::vector<int>{6, 12});
    }
    SECTION("по убыванию") {
        std::vector<int> arr = {12, 6};
        insertion_sort(arr);
        REQUIRE(arr == std::vector<int>{6, 12});
    }
}

TEST_CASE("InsertionSort: double", "[insertion_sort][double]") {
    SECTION("положительные дробные") {
        std::vector<double> arr = {6.0, 3.0, 0.0, 7.0, 2.5, 9.0, 1.0, 4.0};
        insertion_sort(arr);
        REQUIRE(arr == std::vector<double>{0.0, 1.0, 2.5, 3.0, 4.0, 6.0, 7.0, 9.0});
    }
    SECTION("отрицательные и положительные") {
        std::vector<double> arr = {-6.0, 3.0, 0.0, -7.0, 2.5, -9.0, 1.0, 4.0};
        insertion_sort(arr);
        REQUIRE(arr == std::vector<double>{-9.0, -7.0, -6.0, 0.0, 1.0, 2.5, 3.0, 4.0});
    }
    SECTION("пустой массив") {
        std::vector<double> arr;
        insertion_sort(arr);
        REQUIRE(arr.empty());
    }
}
