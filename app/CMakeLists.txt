set(EXECUTABLE_NAME app)
set(EXECUTABLE_SOURCES src/main.cpp)

# Define creation of executable
add_executable(${EXECUTABLE_NAME} ${EXECUTABLE_SOURCES})

# Specify compiler version for executable
set_target_properties(
  ${EXECUTABLE_NAME}
  PROPERTIES CXX_EXTENSIONS OFF
             CXX_STANDARD 20
             CXX_STANDARD_REQUIRED TRUE
             C_STANDARD 17
             C_STANDARD_REQUIRED TRUE)

# Add src and include directory for #include lookup path
target_include_directories(${EXECUTABLE_NAME} PUBLIC include)
target_include_directories(${EXECUTABLE_NAME} PRIVATE src)

# Link project libraries with executable
target_link_libraries(${EXECUTABLE_NAME} glm glad glfw)

if(NOT MSVC)
  # Specify extra warnings for better practice in GCC/Clang.
  target_compile_options(
    ${EXECUTABLE_NAME}
    PRIVATE -Wall
            # -Werror
            -Wextra
            -pedantic
            -Wconversion
            -Wshadow
            -Wold-style-cast
            -Wcast-align
            -Wcast-qual
            -Winit-self
            -Wmissing-field-initializers
            -Woverloaded-virtual
            -Wredundant-decls
            -Wundef
            -fdiagnostics-parseable-fixits)
endif()
