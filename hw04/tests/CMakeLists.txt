include(CTest)

add_executable(hw04_test hw04_test.cpp)

target_link_libraries(hw04_test
    PRIVATE
    GTest::gtest
    hw04
)

add_test(hw04_tests hw04_test)
