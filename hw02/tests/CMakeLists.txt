include(CTest)

add_executable(hw02_test hw02_test.cpp)

target_link_libraries(hw02_test
    PRIVATE
    GTest::gtest
    hw02
)

add_test(hw02_tests hw02_test)
