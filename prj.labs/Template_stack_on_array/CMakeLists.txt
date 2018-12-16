
add_subdirectory(tests_stack_a)
add_library(Template_stack_on_array stack_on_array.h stack_on_array.cpp)
set_property(TARGET Template_stack_on_array PROPERTY CXX_STANDARD 14)
