
add_subdirectory(tests_matrix)
add_library(matrix matrix.cpp matrix.h)
set_property(TARGET matrix PROPERTY CXX_STANDARD 14)
