# Статическая библиотека со всеми сортировками
add_library(sorting STATIC
    src/bubble_sort.cpp
    src/exchange_sort.cpp
    src/insertion_sort.cpp
    src/optimized_bubble_sort.cpp
    src/selection_sort.cpp
)

# PUBLIC — заголовки видны и самой библиотеке, и всем, кто к ней линкуется
target_include_directories(sorting PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Предупреждения компилятора
target_compile_options(sorting PRIVATE
    -Wall -Wextra -Wpedantic
)
