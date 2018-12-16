add_executable(tests_complex complex_test.cpp)
target_link_libraries(tests_complex complex)
set_property(TARGET tests_complex PROPERTY CXX_STANDARD 14)
