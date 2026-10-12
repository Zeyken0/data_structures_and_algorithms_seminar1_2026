#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "bubble_sort.h"
#include <vector>

TEST_CASE("BubbleSort: пустой массив", "[bubble_sort]") {
    std::vector<int> arr;
    bubble_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("BubbleSort: один элемент", "[bubble_sort]") {
    std::vector<int> arr = {12};
    bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{12});
}

TEST_CASE("BubbleSort: уже отсортированный", "[bubble_sort]") {
    std::vector<int> arr = {0, 2, 5, 6, 8, 12, 14, 18};
    bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("BubbleSort: обратный порядок", "[bubble_sort]") {
    std::vector<int> arr = {18, 14, 12, 8, 6, 5, 2, 0};
    bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("BubbleSort: тестовый массив", "[bubble_sort]") {
    std::vector<int> arr = {12, 6, 0, 14, 5, 18, 2, 8};
    bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("BubbleSort: все элементы равны", "[bubble_sort]") {
    std::vector<int> arr = {7, 7, 7, 7, 7};
    bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{7, 7, 7, 7, 7});
}

TEST_CASE("BubbleSort: отрицательные числа", "[bubble_sort]") {
    std::vector<int> arr = {-12, -6, 0, -14, -5, -18, -2, -8};
    bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{-18, -14, -12, -8, -6, -5, -2, 0});
}

TEST_CASE("BubbleSort: два элемента, оба порядка", "[bubble_sort]") {
    SECTION("по возрастанию") {
        std::vector<int> arr = {6, 12};
        bubble_sort(arr);
        REQUIRE(arr == std::vector<int>{6, 12});
    }
    SECTION("по убыванию") {
        std::vector<int> arr = {12, 6};
        bubble_sort(arr);
        REQUIRE(arr == std::vector<int>{6, 12});
    }
}

TEST_CASE("BubbleSort: double", "[bubble_sort][double]") {
    SECTION("положительные дробные") {
        std::vector<double> arr = {6.0, 3.0, 0.0, 7.0, 2.5, 9.0, 1.0, 4.0};
        bubble_sort(arr);
        REQUIRE(arr == std::vector<double>{0.0, 1.0, 2.5, 3.0, 4.0, 6.0, 7.0, 9.0});
    }
    SECTION("отрицательные и положительные") {
        std::vector<double> arr = {-6.0, 3.0, 0.0, -7.0, 2.5, -9.0, 1.0, 4.0};
        bubble_sort(arr);
        REQUIRE(arr == std::vector<double>{-9.0, -7.0, -6.0, 0.0, 1.0, 2.5, 3.0, 4.0});
    }
    SECTION("пустой массив") {
        std::vector<double> arr;
        bubble_sort(arr);
        REQUIRE(arr.empty());
    }
}
