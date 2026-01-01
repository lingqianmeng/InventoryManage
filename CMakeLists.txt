cmake_minimum_required(VERSION 3.10)

project(InventoryManage 
    VERSION 1.0
    DESCRIPTION "A C++ Inventory Management System"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# --- FIX 1: Header Include Path ---
# Since your headers are in src/core, we tell CMake to look there.
# This fixes "fatal error: InventoryManager.h: No such file or directory"
include_directories(src/core) 
# ----------------------------------

# --- FIX 2: Runtime Library Mismatch ---
# Fixes the LNK2038 errors (Static vs Dynamic runtime conflict)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# ---------------------------------------

# --- NEW: Download GoogleTest automatically ---
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE  # <--- Fixes the warning in your 2nd picture
)
# This downloads and makes GTest available to use
FetchContent_MakeAvailable(googletest)

# ----------------------------------------------

# Define core logic files (Everything EXCEPT main.cpp)
# We separate these so we can use them in both the App and the Tests.
# --- FIX 3: Find all Core Source Files ---
# This command automatically finds every .cpp file inside src/core/
# So you don't need to manually type InventoryItem.cpp, Product.cpp, etc.
file(GLOB CORE_SOURCES "src/core/*.cpp")
file(GLOB TEST_SOURCES "tests/*.cpp")

# 1. The Main Application
add_executable(InventoryApp 
    src/main.cpp 
    ${CORE_SOURCES}       # Include all src/core files here
)

# 2. The Test Suite
enable_testing()

# Create a separate executable just for tests
add_executable(unit_tests
    ${TEST_SOURCES}       # Include all your test files
    ${CORE_SOURCES}       # Include all src/core files here
)

# Link GoogleTest to your test executable
target_link_libraries(unit_tests GTest::gtest_main)

# Allow CTest to find these tests
include(GoogleTest)
gtest_discover_tests(unit_tests)