cmake_minimum_required(VERSION 3.6)
project(Template)

# Set C++ standard requirements
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Ensure compilation commands are exported for code completion engines
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Add CryptoPP subdirectory
include_directories(include )
add_subdirectory(cryptopp-cmake)

# Add your module path if needed (you already have this)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# Set global compiler warnings
if(MSVC)
    add_compile_options(/W3 /WX)
else()
    add_compile_options(-Wall -pedantic)
endif()

add_library(mylib 
    src/sha256.cpp 
    src/Block.cpp 
    src/Blockchain.cpp 
    src/Transaction.cpp 
    src/utils.cpp
)

# Link CryptoPP to your library
target_link_libraries(mylib PRIVATE cryptopp::cryptopp)

# # Add main executable and link to mylib
add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE mylib)
