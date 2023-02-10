Base GL Project
================================================================================

Git Instructions
--------------------------------------------------------------------------------

```sh
git clone git@github.com:Chamberlain91/base_gl_project.git
cd base_gl_project
git submodule init
git submodule update
```

Build Instructions (VS Code Extension)
--------------------------------------------------------------------------------

If you have the VS Code `CMake Tools` extension from Microsoft, it is quite easy 
to build and run cmake projects. Press `CTRL + SHIFT + P` to open the command 
menu and select `CMake: Configure`. After this open the menu again and select 
`CMake: Select Variant` and choose `Release` or whatever you'd like.

Finally, open the command menu again and select `CMake: Run without Debugging`.

Build Instructions (Command Line)
--------------------------------------------------------------------------------

Create a directory called `build` and change into it.

```sh
>> mkdir build
>> cd build
```

After this you need to invoke `cmake` to configure the project build files, 
it will use whatever build system it finds first (Visual Studio, Ninja, etc). 
This can be specified by a flag like `-GNinja`, but whatever is default is 
probably fine.

You'll see something like this:

```
PS C:\...\base_gl_project\build> cmake ..
-- Building for: Visual Studio 17 2022
-- Selecting Windows SDK version 10.0.22000.0 to target Windows 10.0.25290.
-- The C compiler identification is MSVC 19.35.32019.0
-- The CXX compiler identification is MSVC 19.35.32019.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: C:/.../bin/Hostx64/x64/cl.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/.../bin/Hostx64/x64/cl.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- GLM: Version 0.9.9.9
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Failed
-- Looking for pthread_create in pthreads
-- Looking for pthread_create in pthreads - not found
-- Looking for pthread_create in pthread
-- Looking for pthread_create in pthread - not found
-- Check if compiler accepts -pthread
-- Check if compiler accepts -pthread - no
-- Found Threads: TRUE
-- Including Win32 support
-- Configuring done
-- Generating done
-- Build files have been written to: C:/.../base_gl_project/build
```

Once that completes you can run cmake to build the project for you.

```sh
>> cmake --config Release --build .
```

**Note**: The config switch `--config Release` or `--config Debug` is only 
useful for Multi-Config build systems (ie, Visual Studio) build types. You must 
(re)configure Ninja or whatever single-target build systems with 
`-DCMAKE_BUILD_TYPE=Release` like the configure step above.
