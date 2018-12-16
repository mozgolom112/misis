
add_subdirectory(tests_queuepriority)
add_library(queuepriority queue_with_priority.cpp Queue_with_priority.h)
set_property(TARGET queuepriority PROPERTY CXX_STANDARD 14)
