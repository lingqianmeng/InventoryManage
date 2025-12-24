cmake_minimum_required(VERSION 3.10)

project(InventoryManage 
    VERSION 1.0
    DESCRIPTION "A C++ Inventory Management System"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# --- NEW: Download GoogleTest automatically ---
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# This downloads and makes GTest available to use
FetchContent_MakeAvailable(googletest)
# ----------------------------------------------

# Define core logic files (Everything EXCEPT main.cpp)
# We separate these so we can use them in both the App and the Tests.
set(CORE_SOURCES
    src/core/InventoryItem.cpp
    src/core/InventoryManager.cpp
)

# 1. The Main Application
add_executable(InventoryApp src/main.cpp ${CORE_SOURCES})

# 2. The Test Suite
enable_testing()

# Create a separate executable just for tests
add_executable(unit_tests 
    tests/test_main.cpp  # We will create this file next
    ${CORE_SOURCES}      # Re-use your logic files here
)

# Link GoogleTest to your test executable
target_link_libraries(unit_tests GTest::gtest_main)

# Allow CTest to find these tests
include(GoogleTest)
gtest_discover_tests(unit_tests)