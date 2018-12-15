add_library(queue queue.hpp queue.cpp ../priority_queue/node.hpp ../priority_queue/node.cpp)
set_property(TARGET queue PROPERTY CXX_STANDARD 14)