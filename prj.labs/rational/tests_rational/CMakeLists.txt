add_executable(tests_rational Rational_tests)
target_link_libraries(tests_rational rational)
set_property(TARGET tests_rational PROPERTY CXX_STANDARD 14)
