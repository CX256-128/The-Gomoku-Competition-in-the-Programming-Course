**You have multiple ways to include Header files here**

1. *If you are in pure console mode with g++*
  ```
  # If you create a xxx.cpp required to include Header files here ".../include"
  g++ -I../include xxx.cpp -o yyy
  ```

2. *If you use VSCode and not enable CMake*
  ```
  # configure your tasks.json in you .vscode folder
  # add one of two lines I show as follows
   
  "-I${workspaceFolder}/../include",  // Relative Path
   
  "-I/path/to/your/headers",          // Absolute Path
  ```

3. *If you have CMake*<br>
  create a file named ```CMakeLists.txt```<br>
  and configure as follows
  ```
  cmake_minimum_required(VERSION X.YY)
  project( _YourProject )

  ......

  # include the directory of the Header files
  include_directories(${CMAKE_SOURCE_DIR}/../include)

  ......

  add_executable(_main _main.cpp)
  ```
