find_package(googletest REQUIRED CONFIG)
find_package(junit-gtest REQUIRED CONFIG)

set(TEST_NAME "nsengine_tests")

add_library(${TEST_NAME} SHARED
    nsengine_tests.cpp)

target_link_libraries(${TEST_NAME} PRIVATE
    ${CMAKE_PROJECT_NAME}
    googletest::gtest
    junit-gtest::junit-gtest)