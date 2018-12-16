
add_subdirectory(tests_rational)
add_library(rational Rational.cpp Rational.h)
set_property(TARGET rational PROPERTY CXX_STANDARD 14)
