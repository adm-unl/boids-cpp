add_library(boids boid.cpp world.cpp rules.cpp utility.cpp)
target_link_libraries(boids PUBLIC cxx_setup)

add_subdirectory(tests)

