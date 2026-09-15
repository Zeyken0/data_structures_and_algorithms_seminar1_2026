# Путь к single-header Catch2 v2
set(CATCH2_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/external/catch2)

# Один исполняемый файл со всеми тестами.
# Функция main() определяется в test_bubble_sort.cpp через CATCH_CONFIG_MAIN.
add_executable(sorting_tests
    test_bubble_sort.cpp
    test_exchange_sort.cpp
    test_insertion_sort.cpp
    test_optimized_bubble_sort.cpp
    test_selection_sort.cpp
)

# Заголовки Catch2
target_include_directories(sorting_tests PRIVATE ${CATCH2_INCLUDE_DIR})

# Линкуем с библиотекой сортировок (PUBLIC-инклюды из sorting протекут автоматически)
target_link_libraries(sorting_tests PRIVATE sorting)

# Предупреждения компилятора
target_compile_options(sorting_tests PRIVATE
    -Wall -Wextra -Wpedantic
)

# Регистрируем в CTest
add_test(NAME sorting_tests COMMAND sorting_tests)
