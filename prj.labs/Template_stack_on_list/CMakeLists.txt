
add_subdirectory(tests_stack_l)
add_library(Template_stack_on_list stack_on_list.h stack_on_list.cpp)
set_property(TARGET Template_stack_on_list PROPERTY CXX_STANDARD 14)
