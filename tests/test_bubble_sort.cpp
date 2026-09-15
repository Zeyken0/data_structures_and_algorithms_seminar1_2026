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
    std::vector<int> arr = {42};
    bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{42});
}

TEST_CASE("BubbleSort: уже отсортированный", "[bubble_sort]") {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("BubbleSort: обратный порядок", "[bubble_sort]") {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("BubbleSort: произвольный порядок", "[bubble_sort]") {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 1, 2, 3, 3, 4, 5, 5, 6, 9});
}

TEST_CASE("BubbleSort: все элементы равны", "[bubble_sort]") {
    std::vector<int> arr = {7, 7, 7, 7, 7};
    bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{7, 7, 7, 7, 7});
}

TEST_CASE("BubbleSort: отрицательные числа", "[bubble_sort]") {
    std::vector<int> arr = {-3, 0, -1, 5, -10, 2};
    bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{-10, -3, -1, 0, 2, 5});
}

TEST_CASE("BubbleSort: два элемента, оба порядка", "[bubble_sort]") {
    SECTION("по возрастанию") {
        std::vector<int> arr = {1, 2};
        bubble_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2});
    }
    SECTION("по убыванию") {
        std::vector<int> arr = {2, 1};
        bubble_sort(arr);
        REQUIRE(arr == std::vector<int>{1, 2});
    }
}

TEST_CASE("BubbleSort: double", "[bubble_sort][double]") {
    SECTION("положительные дробные") {
        std::vector<double> arr = {3.5, 1.25, 2.75, 0.5, 4.0};
        bubble_sort(arr);
        REQUIRE(arr == std::vector<double>{0.5, 1.25, 2.75, 3.5, 4.0});
    }
    SECTION("отрицательные и положительные") {
        std::vector<double> arr = {-1.5, 2.25, -3.75, 0.0, 1.5};
        bubble_sort(arr);
        REQUIRE(arr == std::vector<double>{-3.75, -1.5, 0.0, 1.5, 2.25});
    }
    SECTION("пустой массив") {
        std::vector<double> arr;
        bubble_sort(arr);
        REQUIRE(arr.empty());
    }
}
