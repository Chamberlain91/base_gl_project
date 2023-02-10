# Define GLAD static library
add_library(glad STATIC src/glad.c)

# Include the 'include' dir for #include
target_include_directories(glad PUBLIC include)
