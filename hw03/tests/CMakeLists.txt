include(CTest)

add_executable(hw03_test hw03_test.cpp)

target_link_libraries(hw03_test
    PRIVATE
    GTest::gtest
    hw03
)

add_test(hw03_tests hw03_test)
