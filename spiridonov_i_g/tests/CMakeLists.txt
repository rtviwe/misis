add_executable(tests complex_test.cpp rational_test.cpp dynamic_array_test.cpp matrix_test.cpp queue_test.cpp stack_test.cpp)
target_link_libraries(tests complex rational queue stack dynamic_array matrix)
set_property(TARGET tests PROPERTY CXX_STANDARD 14)