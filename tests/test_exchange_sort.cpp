#include <catch.hpp>
#include "exchange_sort.h"
#include <vector>

TEST_CASE("ExchangeSort: пустой массив", "[exchange_sort]") {
    std::vector<int> arr;
    exchange_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("ExchangeSort: один элемент", "[exchange_sort]") {
    std::vector<int> arr = {99};
    exchange_sort(arr);
    REQUIRE(arr == std::vector<int>{99});
}

TEST_CASE("ExchangeSort: уже отсортированный", "[exchange_sort]") {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    exchange_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("ExchangeSort: обратный порядок", "[exchange_sort]") {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    exchange_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("ExchangeSort: произвольный порядок", "[exchange_sort]") {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    exchange_sort(arr);
    REQUIRE(arr == std::vector<int>{1, 1, 2, 3, 3, 4, 5, 5, 6, 9});
}

TEST_CASE("ExchangeSort: дубликаты", "[exchange_sort]") {
    std::vector<int> arr = {2, 2, 2, 2, 2};
    exchange_sort(arr);
    REQUIRE(arr == std::vector<int>{2, 2, 2, 2, 2});
}

TEST_CASE("ExchangeSort: отрицательные и положительные", "[exchange_sort]") {
    std::vector<int> arr = {-5, 3, -1, 0, 8, -4};
    exchange_sort(arr);
    REQUIRE(arr == std::vector<int>{-5, -4, -1, 0, 3, 8});
}

TEST_CASE("ExchangeSort: double", "[exchange_sort][double]") {
    SECTION("положительные дробные") {
        std::vector<double> arr = {3.5, 1.25, 2.75, 0.5, 4.0};
        exchange_sort(arr);
        REQUIRE(arr == std::vector<double>{0.5, 1.25, 2.75, 3.5, 4.0});
    }
    SECTION("отрицательные и положительные") {
        std::vector<double> arr = {-1.5, 2.25, -3.75, 0.0, 1.5};
        exchange_sort(arr);
        REQUIRE(arr == std::vector<double>{-3.75, -1.5, 0.0, 1.5, 2.25});
    }
    SECTION("пустой массив") {
        std::vector<double> arr;
        exchange_sort(arr);
        REQUIRE(arr.empty());
    }
}
