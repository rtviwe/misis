add_library(stack stack.hpp stack.cpp node.hpp node.cpp)
set_property(TARGET stack PROPERTY CXX_STANDARD 14)
add_subdirectory(test_stack)