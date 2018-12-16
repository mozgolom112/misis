add_executable(tests_matrix matrix_test)
target_link_libraries(tests_matrix matrix)
set_property(TARGET tests_matrix PROPERTY CXX_STANDARD 14)
