#include <catch.hpp>
#include "exchange_sort.h"
#include <vector>

TEST_CASE("ExchangeSort: пустой массив", "[exchange_sort]") {
    std::vector<int> arr;
    exchange_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("ExchangeSort: один элемент", "[exchange_sort]") {
    std::vector<int> arr = {12};
    exchange_sort(arr);
    REQUIRE(arr == std::vector<int>{12});
}

TEST_CASE("ExchangeSort: уже отсортированный", "[exchange_sort]") {
    std::vector<int> arr = {0, 2, 5, 6, 8, 12, 14, 18};
    exchange_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("ExchangeSort: обратный порядок", "[exchange_sort]") {
    std::vector<int> arr = {18, 14, 12, 8, 6, 5, 2, 0};
    exchange_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("ExchangeSort: тестовый массив", "[exchange_sort]") {
    std::vector<int> arr = {12, 6, 0, 14, 5, 18, 2, 8};
    exchange_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("ExchangeSort: дубликаты", "[exchange_sort]") {
    std::vector<int> arr = {12, 6, 0, 14, 5, 18, 2, 8, 12, 6, 0, 14, 5, 18, 2, 8};
    exchange_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 0, 2, 2, 5, 5, 6, 6, 8, 8, 12, 12, 14, 14, 18, 18});
}

TEST_CASE("ExchangeSort: отрицательные и положительные", "[exchange_sort]") {
    std::vector<int> arr = {-12, -6, 0, -14, -5, -18, -2, -8};
    exchange_sort(arr);
    REQUIRE(arr == std::vector<int>{-18, -14, -12, -8, -6, -5, -2, 0});
}

TEST_CASE("ExchangeSort: два элемента, оба порядка", "[exchange_sort]") {
    SECTION("по возрастанию") {
        std::vector<int> arr = {6, 12};
        exchange_sort(arr);
        REQUIRE(arr == std::vector<int>{6, 12});
    }
    SECTION("по убыванию") {
        std::vector<int> arr = {12, 6};
        exchange_sort(arr);
        REQUIRE(arr == std::vector<int>{6, 12});
    }
}

TEST_CASE("ExchangeSort: double", "[exchange_sort][double]") {
    SECTION("положительные дробные") {
        std::vector<double> arr = {6.0, 3.0, 0.0, 7.0, 2.5, 9.0, 1.0, 4.0};
        exchange_sort(arr);
        REQUIRE(arr == std::vector<double>{0.0, 1.0, 2.5, 3.0, 4.0, 6.0, 7.0, 9.0});
    }
    SECTION("отрицательные и положительные") {
        std::vector<double> arr = {-6.0, 3.0, 0.0, -7.0, 2.5, -9.0, 1.0, 4.0};
        exchange_sort(arr);
        REQUIRE(arr == std::vector<double>{-9.0, -7.0, -6.0, 0.0, 1.0, 2.5, 3.0, 4.0});
    }
    SECTION("пустой массив") {
        std::vector<double> arr;
        exchange_sort(arr);
        REQUIRE(arr.empty());
    }
}
