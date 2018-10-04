add_executable(dynamicarray_plus_matrix dynamicarray.cpp dynamicarray.h DynamicArray_Test.cpp matrix.cpp matrix.h Matrix_test.cpp)
set_property(TARGET dynamicarray PROPERTY CXX_STANDARD 14)
