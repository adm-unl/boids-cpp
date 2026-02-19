if (BUILD_TESTING)
    add_executable(boids_tests test_vector.cpp test_boid.cpp test_utility.cpp)
    target_link_libraries(boids_tests PRIVATE GTest::gtest_main boids)

    include(GoogleTest)
    gtest_discover_tests(boids_tests)
endif()

