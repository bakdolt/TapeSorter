add_executable(TapeSorterTests
    TapeSorterTests.cpp
    MockTape.cpp
    MockTape.h
)

target_link_libraries(TapeSorterTests
    PRIVATE
        TapeSorter
        GTest::gtest_main
        GTest::gmock_main
)

target_include_directories(TapeSorterTests
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/TapeSorter
)

include(GoogleTest)
gtest_discover_tests(TapeSorterTests) 