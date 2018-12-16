
add_subdirectory(tests_dynamicarray)
add_library(dynamicarray dynamicarray.cpp dynamicarray.h)

set_property(TARGET dynamicarray PROPERTY CXX_STANDARD 14)