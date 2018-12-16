add_library(complex complex.hpp complex.cpp)
set_property(TARGET complex PROPERTY CXX_STANDARD 14)
add_subdirectory(test_complex)