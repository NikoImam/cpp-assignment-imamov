include(CTest)

add_executable(hw01_test hw01_test.cpp)

target_link_libraries(hw01_test
    PRIVATE
    GTest::gtest
    hw01
)

add_test(hw01_tests hw01_test)
