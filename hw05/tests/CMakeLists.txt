include(CTest)

add_executable(hw05_test hw05_test.cpp)

target_link_libraries(hw05_test
    PRIVATE
    GTest::gtest
    hw05
)

add_test(hw05_tests hw05_test)
