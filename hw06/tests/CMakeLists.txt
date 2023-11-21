include(CTest)

add_executable(hw06_test hw06_test.cpp)

target_link_libraries(hw06_test
    PRIVATE
    GTest::gtest
    hw06
)

add_test(hw06_tests hw06_test)
