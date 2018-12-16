
add_subdirectory(tests_queue)
add_library(Template_queue Queue.cpp Queue.h)
set_property(TARGET Template_queue PROPERTY CXX_STANDARD 14)
