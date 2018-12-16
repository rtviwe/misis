add_library(rational rational.hpp rational.cpp)
set_property(TARGET rational PROPERTY CXX_STANDARD 14)
add_subdirectory(test_rational)
