
cmake_minimum_required(VERSION 3.20)

project(DataVerse
        VERSION 0.1.0
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Dependency Management
include(FetchContent)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
        GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(raylib)

# Automatically discover all source files
file(GLOB_RECURSE DATAVERSE_SOURCES CONFIGURE_DEPENDS
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
)
# Automatically discover all header files
file(GLOB_RECURSE DATAVERSE_HEADERS CONFIGURE_DEPENDS
        "${PROJECT_SOURCE_DIR}/include/*.hpp"
)

# Main Executable
add_executable(DataVerse
        ${DATAVERSE_SOURCES}
        ${DATAVERSE_HEADERS}
)

# Include Directories
target_include_directories(DataVerse PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

# Link Libraries
target_link_libraries(DataVerse PRIVATE
        raylib
)

# Compiler Warnings
if(MSVC)
    target_compile_options(DataVerse PRIVATE /W4)
else()
    target_compile_options(DataVerse PRIVATE
            -Wall
            -Wextra
            -Wpedantic
    )
endif()
