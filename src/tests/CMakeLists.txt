if (BUILD_TESTING)
    add_executable(boids_tests test_boid.cpp test_world.cpp)
    target_link_libraries(boids_tests PRIVATE GTest::gtest_main boids)

    include(GoogleTest)
    gtest_discover_tests(boids_tests)
endif()

