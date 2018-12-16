add_executable(tests_queue queue_test)
target_link_libraries(tests_queue Template_queue)
set_property(TARGET tests_queue PROPERTY CXX_STANDARD 14)
