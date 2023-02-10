cmake_minimum_required(VERSION 3.2)
cmake_policy(VERSION 3.2)

# TODO: RENAME PROJECT TO WHATEVER YOU WANT TO CALL IT
project(base_gl_project VERSION 0.1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COLOR_DIAGNOSTICS ON)
set(CMAKE_COLOR_MAKEFILE ON)

# Sets output directories so its something like "build/dist/bin"
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist/bin)

# Include the external libraries
add_subdirectory(lib)

# Include the app project source code
add_subdirectory(app)
